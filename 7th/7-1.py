import RPi.GPIO as gp
from time import sleep as sl
from time import time
from matplotlib import pyplot

#цап, светодиоды, компаратор и тройка
dac = [26, 19, 13, 6, 5, 11, 9, 10]; leds = [21, 20, 16, 12, 7, 8, 25, 24]
comp = 4; troyka = 17
#настраиваем все нужные нам порты
gp.setmode(gp.BCM)
gp.setup(dac, gp.OUT); gp.setup(leds, gp.OUT)
gp.setup(troyka, gp.OUT, initial=0); gp.setup(comp, gp.IN)

#двоичное число
def binary(value):
    return [int(bit) for bit in bin(value)[2:].zfill(8)]
#напряжение на выходе тройка-модуля
def adc():
    k = 0
    for i in range(7, -1, -1):
        k += 2 ** i
        gp.output(dac, binary(k))
        sl(0.01)
        if gp.input(comp) == 0:
            k -= 2 ** i
    return k

#блок try и finally
try:
    list_of_values = []; start_of_exp = time()
    q = -1; tick = 0
    gp.output(troyka, gp.HIGH)
    while q <= 256 * 0.97:
        q = adc(); # число делений q
        list_of_values.append(q)
        tick += 1;
        gp.output(leds, binary(q))
    print('Charging Done!')
    # заканчиваем зарядку и начинаем разрядку
    gp.output(troyka, gp.LOW)
    while q >= 256 * 0.02:
        q = adc()  # число делений q
        list_of_values.append(q)
        tick += 1
        gp.output(leds, binary(q)) # выводим текущее напряжение
    # разрядка закончена
    print('End of discharging, experiment finished successfully!')
    end_of_exp = round(time() - start_of_exp, 5)
    f = open('data.txt', 'w')
    for i in list_of_values: f.write(str(i) + '\n')
    f.close() # записываем полученные данные в data.txt
    f = open('settings.txt', 'w')
    f.write(str(3.3 / (2 ** 8 - 1)) + ' ' + str(1 / (end_of_exp / tick)))
    f.close() # записываем шаг квантования и среднюю частоту дискретизации в settings.txt
    print(f"Overall time: {round(end_of_exp, 3)}; T = {end_of_exp / tick}; f = {1 / (end_of_exp / tick)}; step = {3.3 / (2 ** 8 - 1)}.") # выводим результаты в консоль
    pyplot.plot([i * (end_of_exp / tick) for i in range(0, tick)], list_of_values)
    pyplot.xlabel('t')
    pyplot.ylabel('Показания АЦП')
    pyplot.show()
finally:
    gp.output(troyka, 0)
    gp.output(dac, 0)
    gp.output(leds, 0)
    gp.cleanup()

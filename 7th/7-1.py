import RPi.GPIO as gp
from time import sleep as sl

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
    for i in range(0, 2 ** len(dac)):
        gp.output(dac, binary(i))
        sl(0.001)
        if gp.input(comp) == 0:
            return i
    raise ValueError

#блок try и finally
try:
    list_of_values = []; start_of_exp = 0
    q = -1
    gp.output(troyka, 1)
    while q <= 247:
        gp.output(troyka, gp.HIGH)
        q = adc(); u = (q / 256) * 3.3  # напряжение u и число делений q
        print(u)
        gp.output(leds, binary(q))
    print('Done!')
    # заканчиваем зарядку и начинаем разрядку
    gp.output(troyka, 0)
    while q >= 6:
        q = adc(); u = (q / 256) * 3.3  # напряжение u и число делений q
        print(q)
        gp.output(leds, [1] * 8 if q >= 245 else [0] * (8 - q // 32) + [1] * (q // 32)) # выводим текущее напряжение
    # разрядка закончена
    print('End of exp!')
    end_of_exp = '???'
    # строим график?

finally:
    gp.output(troyka, 0)
    gp.output(dac, 0)
    gp.output(leds, 0)
    gp.cleanup()
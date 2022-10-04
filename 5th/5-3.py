import RPi.GPIO as gp
from time import sleep as sl
def b(value):
 
    return [int(bit) for bit in bin(value)[2:].zfill(8)]

def adc(): # должны перебором значений от 0 до 255 включительно определить, какое напряжение дает ручка тройка модуля
    n = 0
    for j in range(0, 8):
        if n >= 0:
            gp.output(dac, b(n))
        else:
            gp.output(dac, b(0))
            return 0

        sl(0.0005)
        if gp.input(comp) == 0:
            n -= 2 ** (7 - j)
        else:
            n += 2 ** (7 - j)

    return n

dac = [26, 19, 13, 6, 5, 11, 9, 10]
comp = 4; troyka = 17
gp.setmode(gp.BCM)
gp.setup(dac, gp.OUT)
gp.setup(troyka, gp.OUT, initial = 1); gp.setup(comp, gp.IN)
leds = [21, 20, 16, 12, 7, 8, 25, 24]; gp.setup(leds, gp.OUT)
try:
    while True:
        q = adc()

        u = (q / 256) * 3.3
        gp.output(leds, [1] * 8 if q >= 245 else [0] * (8 - q // 32) + [1] * (q // 32))
        sl(0.5)
#        print(f'Деление: {adc()}, Напряжение равно {round(u, 3)}')
finally:
    gp.setup(troyka, 0)
    gp.setup(dac, 0)
    gp.cleanup()

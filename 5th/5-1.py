import RPi.GPIO as gp
from time import sleep as sl
def b(value):
 
    return [int(bit) for bit in bin(value)[2:].zfill(8)]

def adc(): # должны перебором значений от 0 до 255 включительно определить, какое напряжение дает ручка тройка модуля
    for j in range(256):
        gp.output(dac, b(j))
        sl(0.0005)
        if gp.input(comp) == 0:
            return j
        else:
            n = j
    return n

    
dac = [26, 19, 13, 6, 5, 11, 9, 10]
comp = 4; troyka = 17
gp.setmode(gp.BCM)
gp.setup(dac, gp.OUT)
gp.setup(troyka, gp.OUT, initial = 1); gp.setup(comp, gp.IN)

try:
    while True:
        u = (adc() / 256) * 3.3
        sl(0.05)
        print(f'Деление: {adc()}, Напряжение равно {round(u, 3)}')
finally:
    gp.setup(troyka, 0)
    gp.setup(dac, 0)
    gp.cleanup()
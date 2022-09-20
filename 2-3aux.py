from RPi import GPIO as g
from time import sleep
leds = [21, 20, 16, 12, 7, 8, 25, 24]
aux = [22, 23, 27, 18, 15, 14, 3, 2]
g.setmode(g.BCM); g.setup(leds, g.OUT); g.setup(aux, g.IN)
g.output(leds, 1)
while True:
    for i in range(len(leds)):
        g.output(leds[i], g.input(aux[i]))
    if g.input(2) == 0:
        break
    sleep(0.2)
g.output(leds, 0)
g.cleanup()

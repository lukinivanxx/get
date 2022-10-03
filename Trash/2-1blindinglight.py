import RPi.GPIO as gp
from time import sleep
leds = [21, 20, 16, 12, 7, 8, 25, 24]
gp.setmode(gp.BCM)
gp.setup(leds, gp.OUT)
for i in range(3):
    for j in leds:
        gp.output(j, 1)
        sleep(0.2)
        gp.output(j, 0)
gp.output(leds, 0)
gp.cleanup()

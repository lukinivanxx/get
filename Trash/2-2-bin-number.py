from RPi import GPIO as g
from time import sleep
from random import randint
dac = [26, 19, 13, 6, 5, 11, 9, 10]
#number = [randint(0, 1) for i in range(len(dac))]
number = [0, 0, 0, 0, 0, 0, 0, 0]
g.setmode(g.BCM); g.setup(dac, g.OUT)
g.output(dac, number)
sleep(15)
g.output(dac, 0)
g.cleanup()

from time import sleep
import RPi.GPIO as gp
gp.setmode(gp.BCM)
gp.setup(14, gp.OUT)
for i in range (5):
    gp.output(14, 1); sleep(2)
    gp.output(14, 0); sleep(2)

"""
from time import sleep
import RPi.GPIO as gp
gp.setmode(gp.BCM)
gp.setup(14, gp.OUT)
gp.setup(15, gp.IN)

gp.output(14, gp.input(15))
sleep(2); gp.output(14, 0)
"""

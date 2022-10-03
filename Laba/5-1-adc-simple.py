import RPi.GPIO as gp

def decimal2binary(value):
 
    return [int(bit) for bit in bin(value)[2:].zfill(8)]

def abc()
dac = [26, 19, 13, 6, 5, 11, 9, 10]
comp = 4; troyka = 17;
gp.setmode(gp.BCM); gp.setup(dac, gp.OUT);
gp.setup(troyka, gp.OUT, initial = 0); gp.setup(comp, gp.IN)  # idk about the initial
# WIP

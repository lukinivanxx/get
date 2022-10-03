import RPi.GPIO as gp
try:
    pwm = 22; f = 100
    gp.setmode(gp.BCM)
    gp.setup(pwm, gp.OUT)
    pwmOut = gp.PWM(pwm, f)
    pwmOut.start(0)
    while True:
        dcycle = int(input())
        pwmOut.ChangeDutyCycle(dcycle)
    finally:
        gp.cleanup()

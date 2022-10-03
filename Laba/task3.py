import RPi.GPIO as gp
try:
    pwm = 22; f = 100
    gp.setmode(gp.BCM)
    gp.setup(pwm, gp.OUT)
    pwmOut = gp.PWM(pwm, f)  # pwm - номер выхода, f - частота мерцания. 
    pwmOut.start(0)
    while True:
        dcycle = int(input())
        pwmOut.ChangeDutyCycle(dcycle)  #изменяем duty cycle, то есть меняем то, насколько долго будет гореть диод в 1 периоде (меняем яркость при достаточной частоте)
    finally:
        gp.cleanup()

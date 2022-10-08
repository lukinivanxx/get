from matplotlib import pyplot
f = open('pitest.txt')

n = [float(j) for j in f.readline().split()]
pyplot.plot(n, label="Ряд Нилаканта")

n = [float(j) for j in f.readline().split()]
pyplot.plot(n, label="Предел")

n = [float(j) for j in f.readline().split()]
pyplot.plot(n, label="Ряд Лейбница")

n = [float(j) for j in f.readline().split()]
pyplot.plot(n, label="Формула Эйлера")

n = [float(j) for j in f.readline().split()]
pyplot.plot(n, label="Через арксинус")

pyplot.plot([i for i in range(8)], [3.14159265359 for i in range(8)], label="Собственно Пи")

pyplot.grid()
pyplot.legend()
pyplot.show()
    

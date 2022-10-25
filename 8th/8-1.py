import matplotlib.pyplot as plt
import numpy as np

#заготавливаем график и достаем данные из файлов
fig, ax = plt.subplots(figsize=(8, 5), dpi=200)
settings = np.loadtxt('settings.txt', dtype=float)
values = np.loadtxt('data.txt', dtype=int)

# обратываем полученные из файлов данные (деления преващаем в напряжение, делаем время по шагу квантования, находим общее время)
u = values * 3.3 / 256
time = np.arange(len(u)) * settings[0]
t = settings[0] * len(u)

#находим максимальное и минимальное значение напряжения (минимум ищем после зарядки)
max_u = u.max(); max_t_location = max_u.argmax()
max_t = time[max_t_location]

# настраиваем сетку
plt.grid(which='major', color='#808080', alpha=0.9, lw=0.5)
plt.minorticks_on()
plt.grid(which='minor', color='#C0C0C0', alpha=0.7, lw=0.3)

plt.ylabel('U, В')
plt.xlabel('t, с')

#создаем текст
plt.text(18, 2, "t зарядки = 36.0 с", fontsize=10, color='black')
plt.text(18, 1.8, "t разрядки = 32.42 с", fontsize=10, color='black')
plt.title('График U от t для процесса зарядки-разрядки RC-цепи', fontsize=12, loc='center', fontweight='bold', color='black')

#создаем график и маркеры
plt.plot(time, u, linestyle='-', linewidth=1, color='#000000', label='U(t)')
plt.plot(time[::100], u[::100], 'ro', ms=0.7)
plt.legend()
plt.show()

plt.savefig('results.svg')
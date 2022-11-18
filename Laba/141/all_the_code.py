import math

def MNK(data_x, data_y):  # y = kx + a
    number_of_experiments = len(data_x)
    average_x_times_y = sum([data_x[i] * data_y[i] for i in range(number_of_experiments)]) / number_of_experiments
    average_x_squared = sum([x ** 2 for x in data_x]) / number_of_experiments
    average_y_squared = sum([y ** 2 for y in data_y]) / number_of_experiments
    average_x = sum(data_x) / number_of_experiments
    average_y = sum(data_y) / number_of_experiments

    k = (average_x_times_y - average_x * average_y) / (average_x_squared - average_x ** 2)
    a = average_y - k * average_x
    sigma_k_random = (1 / math.sqrt(number_of_experiments)) * math.sqrt((average_y_squared - average_y ** 2) / (average_x_squared - average_x ** 2) - k ** 2)
    sigma_a_random = sigma_k_random * math.sqrt(average_x_squared - average_x ** 2)

    sigma_T2a = 2 * 0.2 * 0.1
    sigma_a2 = 2 * 0.1
    sigma_k_sys = k * math.sqrt((sigma_T2a / max(data_y) / 2) ** 2 + (sigma_a2 / max(data_x) / 2) ** 2)
    sigma_a_sys = a * math.sqrt((sigma_T2a / max(data_y) / 2) ** 2 + (sigma_a2 / max(data_x) / 2) ** 2)
    sigma_a = math.sqrt(sigma_a_sys ** 2 + sigma_a_random ** 2)
    sigma_k = math.sqrt(sigma_k_sys ** 2 + sigma_k_random ** 2)
    
    return [[k, sigma_k_random, sigma_k_sys, sigma_k], [a, sigma_a_random, sigma_a_sys, sigma_a]]
##math.sqrt((sigma_T2a / max(data_y) / 2) ** 2 + (sigma_a2 / max(data_x) / 2) ** 2)

def average(data_x, sigma_system):
    average_x = sum(data_x) / len(data_x)
    sigma_average_x = math.sqrt((1 / len(data_x)) * sum([(x - average_x) ** 2 for x in data_x]) + sigma_system ** 2)
    return [average_x, sigma_average_x]




def square(data):
    return [i ** 2 for i in data]


f = open('data2.txt')
y = [float(y) for y in f.readline().split()]
x = [float(y) for y in f.readline().split()]
results = MNK(x, y)
f.close()
##print(results)
f = open('data3.txt')
T = [float(t) / 100 for t in f.readline().split()]
print(average(T, 0.2 / 2))

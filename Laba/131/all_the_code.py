import math
def MNK(location):
    f = open(location)
    P, y = [], []
    if location == 'data_латунь.txt' or location == 'data_сталь.txt':
        for i in range(4):
            P += [float(j) for j in f.readline().split()]
            y += [float(j) / 1000 for j in f.readline().split()]
    else:
        for i in range(2):
            P += [float(j) for j in f.readline().split()]
            y += [float(j) / 1000 for j in f.readline().split()]
    data_x, data_y = y, P
    number_of_experiments = len(data_x)
    average_x_times_y = sum([data_x[i] * data_y[i] for i in range(number_of_experiments)]) / number_of_experiments
    average_x_squared = sum([x ** 2 for x in data_x]) / number_of_experiments
    average_y_squared = sum([y ** 2 for y in data_y]) / number_of_experiments
    average_x = sum(data_x) / number_of_experiments
    average_y = sum(data_y) / number_of_experiments

    k = average_x_times_y / average_x_squared

    sigma_k_rand = (1 / math.sqrt(number_of_experiments)) * math.sqrt((average_y_squared / average_x_squared) - k ** 2)
    sigma_k_sys = math.sqrt((0.05 / 2513) ** 2 + (0.005 / max(y)) ** 2)
    sigma_k = math.sqrt(sigma_k_rand ** 2 + sigma_k_sys ** 2)
    f.close()
    return [k, sigma_k_rand, sigma_k_sys, sigma_k]

def avrg(location):
    f = open(location)
    data_x = [float(x) for x in f.readline().split()]
    number_of_experiments = len(data_x)
    average_x = sum(data_x) / number_of_experiments
    sigma_system = 0.01 if 'a' in location else 0.001

    sigma_average_x = math.sqrt((1 / len(data_x)) * sum([(x - average_x) ** 2 for x in data_x]) + sigma_system ** 2)
    f.close()
    return [average_x, sigma_average_x]

latun = MNK('data_латунь.txt')
steel = MNK('data_сталь.txt')
wood1 = MNK('data_дерево1.txt')
wood2 = MNK('data_дерево2.txt')

all_materials = [latun, steel, wood1, wood2]
all_E = []
l = 0.503; sigma_l = 0.001 / 2
a = [0.01897, 0.01796, 0.01694, 0.01707]; sigma_a = [0.00012, 0.00014, 0.00015, 0.00013]
b = [0.00391, 0.00383, 0.01089, 0.01052]; sigma_b = [0.00002, 0.00003, 0.00017, 0.00006]
for i in range(4):
    k = all_materials[i][0]; ai = a[i]; bi = b[i]
    sigma_k = all_materials[i][-1]; sigma_ai = sigma_a[i]; sigma_bi = sigma_b[i]
    E = (k * l ** 3) / (4 * ai * bi ** 3)
    sigma_E = E * math.sqrt((sigma_k / k) ** 2 + (sigma_ai / ai) ** 2 + (3 * sigma_bi / bi) ** 2 + (3 * sigma_l  / l) ** 2)
    all_E.append([E * (10 ** -9), sigma_E * (10 ** -9)])
print(all_E)
'''Средние a и b'''
##print(avrg('a_латунь.txt'))
##print(avrg('b_латунь.txt'))
##print(avrg('a_сталь.txt'))
##print(avrg('b_сталь.txt'))
##print(avrg('a_дерево1.txt'))
##print(avrg('b_дерево1.txt'))
##print(avrg('a_дерево2.txt'))
##print(avrg('b_дерево2.txt'))


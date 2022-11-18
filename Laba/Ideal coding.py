import math
f = open('data.txt')
# МНК
##data_x = [type(x) for x in f.readline().split()]
##data_y = [type(y) for y in f.readline().split()]; number_of_experiments = len(data_x)
def MNK(data_x, data_y, type_of_line):
    if len(data_x) == len(data_y):
        number_of_experiments = len(data_x)
    else:
        return 'Incorrect data input!'
    average_x_times_y = sum([data_x[i] * data_y[i] for i in range(number_of_experiments)]) / number_of_experiments
    average_x_squared = sum([x ** 2 for x in data_x]) / number_of_experiments
    average_y_squared = sum([y ** 2 for y in data_y]) / number_of_experiments
    average_x = sum(data_x) / number_of_experiments
    average_y = sum(data_y) / number_of_experiments
    # Следить за N!
    if type_of_line == 'ab': # y = a + bx
        b = (average_x_times_y - average_x * average_y) / (average_x_squared - average_x ** 2)
        a = average_y - b * average_x
        sigma_b_random = (1 / math.sqrt(number_of_experiments)) * math.sqrt((average_y_squared - average_y ** 2) / (average_x_squared - average_x) - b ** 2)
        sigma_a_random = sigma_b_random * math.sqrt(average_x_squared - average_x ** 2)

        sigma_
        return [[a, sigma_a_random], [b, sigma_b_random]]
    elif type_of_line == 'k': # y = kx
        k = average_x_times_y / average_x_squared
        sigma_k_random = (1 / math.sqrt(number_of_experiments)) * math.sqrt((average_y_squared / average_x_squared) - k ** 2)
        return [k, sigma_k_random]
    else:
        return 'Bad line type input!'
    return 'Something went wrong...'

# Average
def average(data_x, sigma_sys):
    if len(data_x) == len(data_y):
        number_of_experiments = len(data_x)
    else:
        return 'Incorrect data input!'
    average_x = sum(data_x) / number_of_experiments
    # Следить за N!
    sigma_average_x = math.sqrt((1 / number_of_experiments) * sum([(x - average_x) ** 2 for x in data_x]) + sigma_sys ** 2)
    return [average_x, sigma_average_x]

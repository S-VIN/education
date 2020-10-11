# Массив размером 2m + 1, где m — натуральное число, заполнен случайным образом. Найдите в массиве медиану.
import random


def createList(n):
    mas = []
    for i in range(0, n):
        mas.append(random.randint(-100, 99))
    return mas

m = int(input('add m\n'))
n = 2 * m + 1
mas = createList(n)
mas.sort()
print(mas)
print(mas[int(len(mas) / 2)])

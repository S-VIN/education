# 3. В массиве случайных целых чисел поменять местами минимальный и максимальный элементы.
import random
import cProfile


def create(n):
    array = [random.randint(-1000000, 1000000) for _ in range(n)]
    return array


def first(mas):
    # search maximum and minimum and their indexes
    maximum = mas[0]
    minimum = mas[0]
    maxIndex = 0
    minIndex = 0
    for i in range(len(mas)):
        if mas[i] > maximum:
            maxIndex = i
            maximum = mas[i]
        if mas[i] < minimum:
            minIndex = i
            minimum = mas[i]
    mas[maxIndex], mas[minIndex] = mas[minIndex], mas[maxIndex]
    return mas


def second(mas):
    maximum = max(mas)
    minimum = min(mas)
    maxIndex = mas.index(maximum)
    minIndex = mas.index(minimum)
    mas[maxIndex], mas[minIndex] = mas[minIndex], mas[maxIndex]
    return mas


def third(mas):
    maximum = mas[0]
    minimum = mas[0]
    minIndex = 0
    maxIndex = 0
    for i in range(len(mas)):
        if mas[i] > maximum:
            maxIndex = i
            maximum = mas[i]
    for i in range(len(mas)):
         if mas[i] > maximum:
             maxIndex = i
             maximum = mas[i]
    mas[maxIndex], mas[minIndex] = mas[minIndex], mas[maxIndex]
    return mas


def main():
    mas = create(10000000)
    array1 = mas
    array2 = mas
    array3 = mas
    first(array1)
    second(array2)
    third(array3)


cProfile.run('main()')

# величина массива - 10000000
# ncalls  tottime  percall  cumtime  percall filename:lineno(function)
#    1    0.828    0.828    0.828    0.828 1.py:13(first)
#    1    0.000    0.000    0.553    0.553 1.py:30(second)
#    1    1.096    1.096    1.096    1.096 1.py:39(third)
# Вторая функция работает быстрее всего. В ней используются встроенные методы
# питона, которые используют неизвестную мне оптимизацию.

# Первая функция ожидаемо работает быстрее третей, тк в первом варианте 1
# проход по массиву, а в третьей таких проходов 2. То есть сложность в первом
# варианте О(n), а в третьем O(2n)



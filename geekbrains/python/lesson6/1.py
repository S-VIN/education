# 3. В массиве случайных целых чисел поменять местами минимальный и максимальный элементы.
import random
from guppy import hpy

def create(n):
    array = [random.randint(-1000000, 1000000) for _ in range(n)]
    print(h.heap()[0])
    return array


def first(mas):
    # search maximum and minimum and their indexes
    print(50 * '*')
    print(h.heap()[0])
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
    print(h.heap()[0])
    return mas


def second(mas):
    print(50 * '*')
    print(h.heap()[0])
    maximum = max(mas)
    minimum = min(mas)
    maxIndex = mas.index(maximum)
    minIndex = mas.index(minimum)
    mas[maxIndex], mas[minIndex] = mas[minIndex], mas[maxIndex]
    print(h.heap()[0])
    return mas


def third(mas):
    print(50 * '*')
    print(h.heap()[0])
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
    print(h.heap()[0])
    return mas


def main():
    print(h.heap()[0])
    print('create mas')
    mas1 = create(100000)
    mas2 = create(100000)
    mas3 = create(100000)

    print('first')
    first(mas1)
    print('second')
    second(mas2)
    print('third')
    third(mas3)


h = hpy()
main()

# python 3.6 64 битная система
# для подсчета памяти использовал модуль guppy. Он позволяет выводить память,
# которую потребляет программа.


# create mas
#Partition of a set of 102815 objects. Total size = 2880792 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 102815 100  2880792 100   2880792 100 int
#Partition of a set of 202806 objects. Total size = 5680540 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 202806 100  5680540 100   5680540 100 int
#Partition of a set of 302797 objects. Total size = 8480288 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302797 100  8480288 100   8480288 100 int
#first
#**************************************************
#Partition of a set of 302797 objects. Total size = 8480288 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302797 100  8480288 100   8480288 100 int
#Partition of a set of 302800 objects. Total size = 8480372 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302800 100  8480372 100   8480372 100 int
#second
#**************************************************
#Partition of a set of 302797 objects. Total size = 8480288 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302797 100  8480288 100   8480288 100 int
#Partition of a set of 302799 objects. Total size = 8480344 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302799 100  8480344 100   8480344 100 int
#third
#**************************************************
#Partition of a set of 302797 objects. Total size = 8480288 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302797 100  8480288 100   8480288 100 int
#Partition of a set of 302799 objects. Total size = 8480344 bytes.
# Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
#     0 302799 100  8480344 100   8480344 100 int

# По этим данным можно понять, что программа тратит память, когда создает 3
# массива для работы алгоритма. При этом примерно 2Мб тратится на работу
# питона. В предыдущей реализации я создавал один массив и копировал его в 2
# других (mas1 = mas, mas2 = mas, mas3 = mas), но так как в массиве хранятся
# ссылки на данные, то увеличения памяти не было.

# Первый способ оказался самый затратный по памяти, так как дополнительных переменных в
# нём больше всего.

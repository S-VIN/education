#  Отсортируйте по убыванию методом пузырька одномерный целочисленный массив, заданный случайными числами на промежутке [-100; 100). 
import random
import cProfile


def createList(n):
    mas = []
    for i in range(0, n):
        mas.append(random.randint(-100, 99))
    return mas


def checkMas(mas):
    for i in range(0, len(mas) - 1):
        if(mas[i] < mas[i + 1]):
            return False
    return True

# идея усовершенствования такая: мы 10 раз проверяем отсортирован ли массив.
# Если он отсортировался за половину проходов, то дальше можно не сортировать.
# Практика показала, что на случайных массивах прирост в производительности
# незначительный, однако на почти отсортированных массивах это должно сильно
# ускорять сортировку.
def newBubbleSort(mas):
    check = int(len(mas) / 10)
    for i in range(0, len(mas)):

        if(i % check == 0):
            if(checkMas(mas)):
                return mas

        for j in range(0, len(mas) - 1):
            if(mas[j] < mas[j + 1]):
                mas[j], mas[j + 1] = mas[j + 1], mas[j]

    return mas


def bubbleSort(mas):
    for i in range(0, len(mas)):
         for j in range(0, len(mas) - 1):
            if(mas[j] < mas[j + 1]):
                mas[j], mas[j + 1] = mas[j + 1], mas[j]
    return mas


def main():
    newBubbleSort(createList(10000))
    bubbleSort(createList(10000))

print(bubbleSort(createList(int(input('write the length of array\n')))))
cProfile.run('main()')

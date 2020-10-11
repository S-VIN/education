# 6. В одномерном массиве найти сумму элементов, находящихся между минимальным и максимальным элементами. Сами минимальный и максимальный элементы в сумму не включать.
# add list of numbers
mas = []
print('add elements of array')
print('0 - end of array')
while True:
    element = int(input())
    if element == 0:
        break
    mas.append(element)

print(f'your list: {mas}')

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

# find sum from maxIndex to minIndex
sum = 0
if maxIndex > minIndex:
    maxIndex, minIndex = minIndex, maxIndex
for i in range(maxIndex, minIndex + 1):
    sum += mas[i]
print(f'answer: {sum - maximum - minimum}')

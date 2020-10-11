# 3. В массиве случайных целых чисел поменять местами минимальный и максимальный элементы.
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
mas[maxIndex], mas[minIndex] = mas[minIndex], mas[maxIndex]

print(f'answer:    {mas}')

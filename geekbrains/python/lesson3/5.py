# В массиве найти максимальный отрицательный элемент.
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
# flag needed for initialise maximum
maximum = mas[0]
flag = True
maxIndex = 0
for i in range(len(mas)):
    if flag:
        if mas[i] < 0:
            flag = False
            maximum = mas[i]
            maxIndex = i
    if mas[i] < 0:
        if mas[i] > maximum:
            maxIndex = i
            maximum = mas[i]

if flag:
    print('all elements of array are positive')
else:
    print(f'answer: {maximum} with index: {maxIndex}')

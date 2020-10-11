# 7. В одномерном массиве целых чисел определить два наименьших элемента.
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

# search minimum
minimumFirst = mas[0]
minIndex = 0
for i in range(len(mas)):
    if mas[i] < minimumFirst:
        minIndex = i
        minimumFirst = mas[i]

mas.pop(minIndex)

minimumSecond = mas[0]
for i in range(len(mas)):
    if mas[i] < minimumSecond:
        minimumSecond = mas[i]
print(f'first minimum: {minimumFirst}, second minimum: {minimumSecond}')

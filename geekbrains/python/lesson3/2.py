# 2. Во втором массиве сохранить индексы четных элементов первого массива.
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

answer = []
for i in range(len(mas)):
    if mas[i] % 2 == 0:
        answer.append(i)
print(f'answer: {answer}')

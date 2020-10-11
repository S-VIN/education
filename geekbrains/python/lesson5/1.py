# 1. Пользователь вводит данные о количестве предприятий, их наименования и
# прибыль за четыре квартала для каждого предприятия. Программа должна
# определить среднюю прибыль (за год для всех предприятий) и отдельно вывести
# наименования предприятий, чья прибыль выше среднего и ниже среднего.
import collections

n = int(input('add quantity of fabrics \n'))

mas = []
allAverage = 0
fabric = collections.defaultdict()

for i in range(0, n):
    fabric['name'] = input(f'name of {i} fabric: ')
    fabric['p1'] = int(input('first quarter profit: '))
    fabric['p2'] = int(input('second quarter profit: '))
    fabric['p3'] = int(input('third quarter profit: '))
    fabric['p4'] = int(input('fourth quarter profit: '))
    fabric['average'] = (fabric['p1'] + fabric['p2'] + fabric['p3'] + fabric['p4']) / 4.0
    allAverage += fabric['average']
    mas.append(collections.defaultdict.copy(fabric))

allAverage /= float(n)

# print(mas)

print(f'\nmiddle average = {allAverage}')
print('\nfabrics with big average:')
name = 'name'
average = 'average'

print()
for i in range(0, n):
    if(mas[i][average] >= allAverage):
        print(f'{mas[i][name]} with average {mas[i][average]}')

print()
print('fabrics with small average')
for i in range(0, n):
    if(mas[i][average] < allAverage):
        print(f'{mas[i][name]} with average {mas[i][average]}')

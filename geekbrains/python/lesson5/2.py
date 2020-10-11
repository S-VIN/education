# Написать программу сложения и умножения двух шестнадцатеричных чисел.
# При этом каждое число представляется как массив, элементы которого —
# цифры числа.
import collections


def decFromList(a):
    # заменяем в массиве буквы на числа
    Hex = collections.OrderedDict({'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15})
    for i in range(0, len(a)):
        a[i] = Hex[a[i]]
    # переводим в 16 систему счисления
    result = 0
    for i in range(len(a) - 1, -1, -1):
        result += a[i] * (16 ** (len(a) - i - 1))
    return result


def hexFromDec(a):
    result = []
    while(True):
        result.append(a % 16)
        if(a // 16 == 0):
            break
        else:
            a //= 16
    result.reverse()
    for i in range(len(result)):
        if (result[i] > 9):
            result[i] = chr(result[i] + 55)
        else:
            result[i] = chr(result[i] + 48)
    return str(result)


a = list(input('add first number  '))
b = list(input('add second number '))

print(a)
print(b)

a1 = decFromList(a)
b1 = decFromList(b)

print(f'sum: {hexFromDec(a1 + b1)}')
print(f'mult: {hexFromDec(a1 * b1)}')

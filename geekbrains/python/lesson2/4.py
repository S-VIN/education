# 4. Найти сумму n элементов следующего ряда чисел: 1, -0.5, 0.25, -0.125,… Количество элементов (n) вводится с клавиатуры.
n = int(input('add n \n'))
i = 0
prev = 1
out = prev
for i in range(n - 1):
    prev = prev / (-2)
    out += prev
print(f'sum of the sequence: {out}')

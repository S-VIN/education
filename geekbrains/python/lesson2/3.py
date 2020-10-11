# 3. Сформировать из введенного числа обратное по порядку входящих в него цифр и вывести на экран.
num = int(input('add your number \n'))
out = 0
while num > 0:
    temp = num % 10
    out *= 10
    out += temp
    num = num // 10
print(f'reverced number: {out}')

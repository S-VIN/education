# 2. Посчитать четные и нечетные цифры введенного натурального числа.
num = int(input('add your number \n'))
even = 0
odd = 0
while num > 0:
    temp = num % 10
    if temp % 2 == 0
        even += 1
    else:
        odd += 1
    num = num // 10
print("there are {} even numbers".format(even))
print("there are {} odd numbers".format(odd))

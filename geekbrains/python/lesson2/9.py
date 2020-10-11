# 9. Среди натуральных чисел, которые были введены, найти наибольшее по сумме цифр. Вывести на экран это число и сумму его цифр.
def sumOfNum(input):
    sum = 0
    while input > 0:
        sum += input % 10
        input //= 10
    return sum


print('add your numbers')
print('0 - end of adding')
sum = 0
maxNum = 0
while True:
    num = int(input())
    if num == 0:
        break
    if sumOfNum(num) > sum:
        maxNum = num
        sum = sumOfNum(num)
print(f'max number: {maxNum} with sum: {sum}')

import cProfile

def erSimple(n):
    k = 1000
    if n == 1: return 1
    mas = makeMas(k)
    while(len(mas) < n):
        k *= 2
        mas = makeMas(k)
    return mas[n - 2]


def makeMas(n):
    sieve = [i for i in range(n)]
    sieve[1] = 0
    for i in range(2, n):
        if sieve[i] != 0:
            j = i * 2
            while j < n:
                sieve[j] = 0
                j += i
    result = [i for i in sieve if i != 0]
    return result


def simple(n):
    i = 0
    j = 1
    while i < n:
        if isSimple(j):
            i += 1
        j += 1
    return j - 1


def isSimple(a):
    if (a == 0) or (a == 1): return True
    for i in range(2, a - 1):
        if (a % i == 0): return False
    return True


def main():
    a = 10000
    print(simple(a))
    print(erSimple(a))

cProfile.run('main()')

#   ncalls  tottime  percall  cumtime  percall filename:lineno(function)
#        8    0.071    0.009    0.088    0.011 2.py:13(makeMas)
#        1    0.001    0.001    0.089    0.089 2.py:3(erSimple)

#   104723   28.926    0.000   28.926    0.000 2.py:36(isSimple)
#        1    0.022    0.022   28.948   28.948 2.py:26(simple)

# Вариант с решетом эратосфена работает гораздо быстрее. Он основан на
# расширении диапазона массива простых чисел в 2 раза, если в нем не достаточно их
# При этом основное время занимает создание этого массива.

# Второй вариант с проверкой каждого числа на простоту работает дольше из-за
# долгой проверки.

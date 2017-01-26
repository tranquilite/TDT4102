def isFibonacciNumber(n):
    a = 0
    b = 1

    while (b < n):
        temp = b
        b += a
        a = temp

    return b==n


def isFibonacciNumber_defensive(n: str) -> bool:
'''Se PEP484'''
    a = int(0)
    b = int(1)

    while(b < n):
        temp = int(b)
        b += int(a)
        a = temp

    return b==n

print(isFibonacciNumber(4))

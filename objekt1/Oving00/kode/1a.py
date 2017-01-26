def isFibonacciNumber(n):
    a, b = 0, 1
    while b < n:
        temp = b
        b += a
        a = temp
    if b is n:
        return True
    else:
        return False

# må nesten teste koden
if __name__ == "__main__":
    for e in [21, 23, 18, 3, 5, 4]:
        if isFibonacciNumber(e) == True:
            print("1")
        else:
            print("0")

def isPrime(n):
    primeness = True
    for j in range(2, n):
        if n%j == 0:
            primeness = False
            break
    return primeness

def naivePrimeNumberSearch(n):
    for number in range(2, n):
        if isPrime(number):
            print('{} is a prime'.format(number))

def findGreatestDivisor(n):
    for divisor in range(n-1, 0, -1):
        if n%divisor == 0:
            return divisor
    return False

if __name__ == '__main__':
    print(isPrime(12))
    for e in range(12,13):
        naivePrimeNumberSearch(e)
        print(findGreatestDivisor(e))

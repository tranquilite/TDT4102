def squareNumberSum(n):
    totalSum = 0
    for i in range(n):
        totalSum += i*i
        print(i*i)
    return totalSum

if __name__ == '__main__':
    squareNumberSum(12)

def isTriangle(number):
    acc = 1
    while number > 0:
        number -= acc
        acc += 1
    return number == 0

if __name__ == '__main__':
    for e in range(0, 10):
        print(isTriangle(e))

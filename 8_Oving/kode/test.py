
def read_lines():
    with open('test.txt', mode='r', newline='\n') as fil:
        a =fil.readlines()
        print(a)

if __name__ == '__main__':
    read_lines()

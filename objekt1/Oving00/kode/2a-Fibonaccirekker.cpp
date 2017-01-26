#include<iostream>
using namespace std;

/*
def fibonacci(n):
    a, b = 0, 1
    print("Fibonacci numbers:")
    for x in range(1,n):
        temp = b
        b = a + b
        a = temp
        print(x,b)
    print()
    return b
*/

int fibonacci(int n) {
    int a = 0, b = 1, temp = 0;
    cout << "Fibonacci numbers:" << endl;
    for (int i = 1; i < n; i++) {
        temp = b;
        b = a + b;
        a = temp;
        cout << i << " " << b << endl;
        }
    return b;
}

//Må jo nesten kjøre, sånn bare for å teste.
int main() {
    fibonacci(8);
    return 0;
}

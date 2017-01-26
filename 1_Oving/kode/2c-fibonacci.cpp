#include<iostream>

int fibonacci(int);
bool tests(); //ork. Kom aldri så langt.

int main() {
    fibonacci(12);
    return 0;
}


int fibonacci(int n) {
    int a = 0;
    int b = 1;
    std::cout << "Fibonacci numbers:" << std::endl;
    for (int i=1; i < n+1; i++) {
        std::cout << i << ", " << b << std::endl;
        int temp = b;
        b += a;
        a = temp;
    }
    std::cout << "----" << std::endl;
    return b;
}


bool tests() {
    int values[] = {1, 15, 26, 12, 11, 18, 24};
    return 0;
}

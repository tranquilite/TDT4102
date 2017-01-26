#include<iostream>
#define lf std::endl;

bool isPrime(int);
void naivePrimeNumberSearch(int);

int main() {
    std::cout << isPrime(12) << lf;
    naivePrimeNumberSearch(12);
    return 0;
}

bool isPrime(int n) {
    bool primeness = true;
    for (int e = 2; e < n; e++) {
        if (n % e == 0) {
            primeness = false;
            break;
        }
    }
    return primeness;
}

void naivePrimeNumberSearch(int n) {
    for (int number = 2; number < n; number++) {
        if (isPrime(number)) {
            std::cout << number << " is a prime" << lf;
        }
    }
}

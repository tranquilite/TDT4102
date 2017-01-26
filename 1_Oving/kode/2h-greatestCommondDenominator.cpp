#include<iostream>
#define lf std::endl;

int findGreatestDivisor(int);

int main() {
    int test[8] = {-2, 3, 4, 6, 7, 42, 41, 40}; 
    for(int i = 0; i < 8; i++) {
        std::cout << findGreatestDivisor(test[i]) << lf;
    }

    return 0;
}

int findGreatestDivisor(int n) {
    if(n < 0) { n = n*-1; }
    for(int divisor = n-1; divisor >= 0; divisor--) {
        if (n % divisor == 0) {
            return divisor;
        }
    }
    return false;
}

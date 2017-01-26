#include<iostream>

double squareNumberSum(int);

int main() {
    squareNumberSum(12);
    return 0;
}

double squareNumberSum(int n) {
    double totalSum = 0;
    for (int i=0; i < n; i++) {
        totalSum += (i*i);
        std::cout << (i*i) << std::endl;
    }
    std::cout << totalSum << std::endl;

    return totalSum;
}

#include<iostream>
#define lf std::endl //latskap

int triangleNumbersBelow(int);
bool isTriangle(int);

int main() {
    triangleNumbersBelow(12);

    int testy[6] = {2, 3, 6, 11, 42, 6};
    for(int i=0; i<6; i++) {
        std::cout << testy[i] << ": " << isTriangle(testy[i]) << lf;
    }
    return 0;
}

int triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    std::cout << "Triangle numbers below " << n << ": " << lf;

    while (acc < n) {
        std::cout << acc << lf;
        acc += num; num += 1;
    }
    std::cout << lf;
    return 0;
}

bool isTriangle(int number) {
    int acc = 1;
    while (number > 0) {
        number -= acc;
        acc += 1;
    }
    return number == 0;
}

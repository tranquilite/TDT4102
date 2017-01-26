#include<iostream>
using namespace std;
#include"AlleTilAlle.h"

//2A - Fibonaccirekker
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

//2B - Trekanttall
// Fig. 12
void triangleNumbersBelow(int n) {
    int acc = 1, num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while((acc+num) < n){
        acc = acc+num;
        num++;
        cout << acc << endl;
    }
}

//Fig. 13
bool isTriangleNumber(int number){
    int acc = 1;
    while(number > 0) {
        number = number - acc;
        acc = acc + 1;
    }
    if(number == 0) {
        return true;
    } else {
        return false;
    }
}

//2C - Sum av kvadrerte tall
int squareNumberSum(int n) {
    int totalSum = 0;
    int e = 0;
    for(int i = 0; i < n; i++) {
        totalSum += i*i;
        e = i+1;
        cout << (e*e) << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}
//2D - Største tall
int max(int a, int b) {
    if(a > b) {
        cout << "a is greater than b" << endl;
        return a;
    } else {
        cout << "a is greater than, or equal, to b" << endl;
        return b;
    }
}

//2E - Primtall 1
bool isPrime(int n) {
    bool primeness = true;
    for(int i = 2; i < n; i++) {
        if(n%i == 0) {
            primeness = false;
            return primeness;
        }
    }
    return primeness;
}

//2F - Primtall 2
void naivePrimeNumberSearch(int n) {
    for(int i = 2; i < n; i++) {
        if(isPrime(i)) {
            cout << i << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n) {
    if(n < 0) {  n = n*-1; }
    for(int i = n-1; n > 0; i--) {
        if(n%i == 0) {
            return i;
        }
    }
    return 0;
}

void compareListOfNumbers(int len, int liste[]) {
    int r[3] = {0, 0, 0};
    // Array er ikke iterable som i python.
    for(int i = 0; i < len; i++) {
        if(liste[i] < 0) {
            r[0]++;
        }
        else if(liste[i] == 0) {
            r[1]++;
        }
        else {
            r[2]++;
        }
    }
    cout << r[0] << " numbers were below zero" << endl;
    cout << r[1] << " numbers were zero" << endl;
    cout << r[2] << " numbers were above zero" << endl;
}

//Må jo nesten kjøre, sånn bare for å teste.
int main() {
    TestMeister Tester;
    Tester.RunTest(); 
    return 0;
}

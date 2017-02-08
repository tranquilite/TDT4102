#include<iostream>

#include"utilities.h"
#include "tests.h"

using std::cout;
using std::endl;


int main() {
    int test[10];
    randomizeArray(test, 10);
    printArray(test, 10);
    return 0;
}


    /*testByCallValue();
    testByCallPointer();*/
    /*int a = 1, b = 2;
    cout << a << "   " << b << endl;
    swapNumbers(&a, &b);
    cout << a << "   " << b << endl;
    int test[5] = {0, 4, 2, 6, 9};
    printArray(test, 5);*/

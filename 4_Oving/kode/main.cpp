#include<iostream>

#include"utilities.h"
#include "tests.h"

using std::cout;
using std::endl;


int main() {/*
    testByCallValue();
    testByCallPointer();*/
    int a = 1, b = 2;
    cout << a << "   " << b << endl;
    swapNumbers(&a, &b);
    cout << a << "   " << b << endl;
    return 0;
}

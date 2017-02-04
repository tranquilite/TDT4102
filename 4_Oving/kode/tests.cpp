#include<iostream>

#include "utilities.h"

using std::cout;
using std::endl;

void testByCallValue() {
    int v0 = 0;
    int increment = 2;
    int iterations = 20;
    //v0 = 0;
    int result = incrementByNumTimesValue(v0, increment, iterations);
    //v0 = 0;
    cout << "v0: " << v0 << endl
         << "increment: " << increment << endl
         << "iterations: " << iterations << endl
         << "result: " << result << endl;
}

void testByCallValue2() {
    int *v0 = 0;
    int increment = 2;
    int iterations = 20;
    //v0 = 0;
    int result = incrementByNumTimesValue2(v0, increment, iterations);
    //v0 = 40
    cout << "v0: " << v0 << endl
         << "increment: " << increment << endl
         << "iterations: " << iterations << endl
         << "result: " << result << endl;
}

int main() {
    testByCallValue2();

    return 0;
}

#include<iostream>

#include "utilities.h"

using std::cout;
using std::endl;

//DEL 1 - Call By Value Vs. Pekere (15&)
void testByCallValue() {
    int v0 = 0;
    int increment = 2;
    int iterations = 20;
    //v0 = 0;
    int result = incrementByNumTimesValue(v0, increment, iterations);
    //v0 = 0;
    cout << "testByCallValue" << endl   
         << "v0: " << v0 << endl
         << "increment: " << increment << endl
         << "iterations: " << iterations << endl
         << "result: " << result << endl << endl;
}

void testByCallPointer() {
    int v0 = 0;
    int increment = 2;
    int iterations = 20;
    //v0 = 0;
    int result = incrementByNumTimesValue2(&v0, increment, iterations);
    //v0 = 40
    cout << "testByCallPointer" << endl   
         << "v0: " << v0 << endl
         << "increment: " << increment << endl
         << "iterations: " << iterations << endl
         << "result: " << result << endl;
}


//DEL 2 - TABELLER (Arrays) 10%
void testTableSorting() {
    int percentages[20];
    randomizeArray(percentages, 20);
    printArray(percentages, 20);
    cout << medianValue(percentages, 20) << endl;
    sortArray(percentages, 20);
    printArray(percentages, 20);
    cout << medianValue(percentages, 20) << endl;
}

//DEL 4 - Char strenger
void testCStrings() {
    enum Karakter {A = 65, B, C, D, E, F};
    Karakter lower = A;
    Karakter upper = F;
    char *Grades = new char[9]; //og så driter vi å debugge litt
    randomizeCString(Grades, 9, lower, upper);
    cout << Grades;
}

void testCStrings2() {
    enum Karakter {A = 65, B, C, D, E, F}; //idiot.
    Karakter lower = A, upper = E;
    char *Grades = new char[41];
    //randomizeCString(Grades, 41, lower, upper);
    readInputToCString(Grades, 41, lower, upper);
    cout << Grades;
}

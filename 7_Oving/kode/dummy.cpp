#include<iostream>

using namespace std;

#include"dummy.h"

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b(a);
    Dummy c;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    cin.get();
}

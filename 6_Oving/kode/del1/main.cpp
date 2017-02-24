#include<iostream>

using std::cout;
using std::endl;

#include"Person.h"
#include"Car.h"
#include"Meeting.h"
#include "tests.h"

using namespace del1;

int main() {
    cout << std::endl;

    //testSFML();
    //testPerson();

    Meeting T;
    cout << T.getStart();

    cout << endl << endl;
    return 0;
}

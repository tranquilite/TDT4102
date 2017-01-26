#include<iostream>

#include"matrise.h"
#include"vektor2.h"

using std::cout;
using std::endl;

void lekeplass();
void _426();

int main() {
    Matrise test; // (1, 0, 0, 1);
    Matrise test2(2, 4, 6, 8); 
    Matrise test3(1, 3, 5, 7); 

    //cout << test3 << endl << test2 << endl << "---------" << endl;
    //cout << test3 * test2 << endl << test3;
    //test3 *= test2;
    //cout << test3;

    //lekeplass();
    _426();
    return 0;
}

void _426() {
    Vektor2 vekt(12, 4);
    cout << vekt.lengde() << endl;
}

void lekeplass() {
    Matrise A(1, 2, 3, 4);
    Matrise B(4, 3, 2, 1);
    Matrise C(1.0, 3.0, 1.5, 2.0);
    Matrise D;
    //cout << A << endl << B << endl;
    //A += B;
    //cout << A << endl << B << endl << " -------- " << endl;
    //A -= B;
    //cout << A << endl << B << endl << " -------- " << endl;
    //D = A + B; //DERP DERP
    //D = D*B - A+C; // Note to self : Stemmer med w|alpha
    //{{1, 0},{0,1}}*{{4,3},{2,1}} - {{1,2},{3,4}} + {{1.0,3.0},{1.5, 2.0}}
    //cout << D;
}

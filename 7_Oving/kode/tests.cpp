#include<iostream>

using std::cout;
using std::endl;

#include"matrix.h"

void matriser() {
    Matrix T;
    Matrix E(10, 5);
    Matrix S(10);

    std::cout << "\nT: " << (T.isValid()?"Gyldig":"Ikke-gyldig") << "\n";
    std::cout << "\nE: " << (E.isValid()?"Gyldig":"Ikke-gyldig") << "\n";
    std::cout << "\nS: " << (S.isValid()?"Gyldig":"Ikke-gyldig") << "\n";
    std::cout << T;
    std::cout << E;
    std::cout << S;
}


void matriser2() {
    Matrix A(2, 2);
    A.set(0,0, 1.0);
    A.set(1,0, 3.0);
    A.set(0,1, 2.0);
    A.set(1,1, 4.0);
    std::cout << A;

    Matrix B(2, 2);
    B.set(0,0, 4.0);
    B.set(1,0, 2.0);
    B.set(0,1, 3.0);
    B.set(1,1, 1.0);
    std::cout << B;

    Matrix C(2, 2);
    C.set(0,0, 1.0);
    C.set(1,0, 1.5);
    C.set(0,1, 3.0);
    C.set(1,1, 2.0);
    std::cout << C;

    A += B + C;

    std::cout << A; std::cout << std::endl;
    std::cout << B; std::cout << std::endl;
    std::cout << C;
}

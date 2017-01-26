#include<iostream>
#include<cmath>

#include"vektor2.h"


Vektor2::Vektor2() {
    vektor[0] = 1;
    vektor[1] = 0.0;
}


Vektor2::Vektor2(double _x, double _y) {
    vektor[0] = _x;
    vektor[1] = _y;
}

double Vektor2::dot(const Vektor2 &rhs) {
    double __00, __10;
    for(int i=0; i < 2; i++) { }

    Vektor2(__00, __10);

    return 0.0;
}


double Vektor2::lengde_kvadrat() const {
    //hardkode. Uflaks. Note: Kom tilbake.
    return (pow(vektor[0], 2) + pow(vektor[1], 2));
}


double Vektor2::lengde() const {
    return sqrt( lengde_kvadrat() );
}


std::ostream& operator<<(std::ostream& _ut, const Vektor2& rhs) {
    _ut << rhs.vektor[0] << std::endl << rhs.vektor[1] << std::endl;
    return _ut;
}


//Note: Dette burde håndteres på en helt annen måte.
//På "SKRIV DETTE PÅ NYTT"-måten.
const Vektor2 operator+(const Vektor2& lhs, const Vektor2& rhs) {
    Vektor2 __arbeidsplass;
    __arbeidsplass.vektor[0] = lhs.vektor[0] + rhs.vektor[0];
    __arbeidsplass.vektor[1] = lhs.vektor[1] + rhs.vektor[1];
    return __arbeidsplass;
}

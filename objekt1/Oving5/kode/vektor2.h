#ifndef VEKTOR2_H
#define VEKTOR2_H
#include<iostream>
#include<cstdlib>

using std::ostream;

class Vektor2 {
public:
    double                  dot(const Vektor2& rhs);
    double                  lengde_kvadrat() const;
    double                  lengde() const;

    //He's my best friend, best of all best friends
    friend          ostream& operator<<(ostream& _ut, const Vektor2& rhs);
    friend  const   Vektor2 operator+(const Vektor2& lhs, const Vektor2& rhs);
    friend  const   Vektor2 operator-(const Vektor2& lhs, const Vektor2& rhs);
    friend          Vektor2 operator+=(Vektor2& lhs, const Vektor2& rhs);
    friend          Vektor2 operator-=(Vektor2& lhs, const Vektor2& rhs);
    //Do you have a best friend too?
    //It tickles in my tummy, he's so yummy yummy, oh, do you have a best friend too?
    
    Vektor2();
    Vektor2(double, double);

private:
    double          vektor[2];      //Er predikert todim. Ingen unntak
};


#endif

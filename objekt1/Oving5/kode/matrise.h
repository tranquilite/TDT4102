#ifndef KLASSE_H
#define KLASSE_H
#include<iostream>
#include<cstdlib>

//Husk å sette i klasse.cpp!
#define størrelse 2

class Matrise {
public:
                    double  les(int rad, int kolonne) const;
                    void    sett(int rad, int kolonne, double element);
                    double det() const;
                    Matrise inverse() const;
                    int     dimensjon;

    friend          std::ostream& operator<<(std::ostream& _ut, const Matrise& rhs);
            const   Matrise operator=(const Matrise& rhs); //Note: Sjekk meg.
    friend  const   Matrise operator+(const Matrise& lhs, const Matrise& rhs);
    friend          Matrise operator+=(Matrise& lhs, const Matrise& rhs);
    friend  const   Matrise operator-(const Matrise& lhs, const Matrise& rhs);
    friend          Matrise operator-=(Matrise& lhs, const Matrise& rhs);
    friend  const   Matrise operator*(const Matrise& lhs, const Matrise& rhs);
    friend  const   Matrise operator*(const int& lhs, const Matrise& rhs);
    //friend  const   Vektor2 operator*(const Matrise& lhs, const Vektor rhs);
    friend          Matrise operator*=(Matrise& lhs, const Matrise& rhs);

    Matrise();
    Matrise(double, double, double, double);

private:
    double      matrise[størrelse][størrelse];
};


#endif

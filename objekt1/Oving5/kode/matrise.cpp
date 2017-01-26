#include<iostream>
#include<cstdlib>

#include"matrise.h"
#include"vektor2.h"

//husk å sette i klasse.h!
#define størrelse 2


Matrise::Matrise() {
    dimensjon = størrelse;
    //og alle er flinke og husker m*n-notasjon fra linalg
    for(int m=0;m < størrelse; m++) {
        for(int n=0; n < størrelse; n++) {
            if(n == m) {
                matrise[m][n] = 1;
            } else {
                matrise[m][n] = 0.0;
            }
        }
    }
}


Matrise::Matrise(double _00, double _01, double _10, double _11) {
    dimensjon = størrelse; //juks, juks, juks
    //Kodegjenbruk. En funksjon eksisterer.
    sett(0, 0, _00);
    sett(0, 1, _01);
    sett(1, 0, _10);
    sett(1, 1, _11);
}


double Matrise::les(int rad, int kolonne) const {
    return this->matrise[rad][kolonne];
}


void Matrise::sett(int rad, int kolonne, double element) {
    this->matrise[rad][kolonne] = element;
}


double Matrise::det() const {
    double __latskap;
    __latskap   =   matrise[0][0]
                *   matrise[1][1]
                -   matrise[0][1]
                *   matrise[1][1];
    return __latskap;
}


Matrise Matrise::inverse() const {
    Matrise __latskap; //PEP-8, "woo"

    return __latskap;
}


std::ostream& operator<<(std::ostream& _ut, const Matrise& rhs) {
    for(int rad=0; rad < størrelse; rad++) {
        for(int kolonne=0; kolonne < størrelse; kolonne++) {
            _ut << rhs.les(rad, kolonne) << "\t";
        }
    _ut << std::endl;
    }
    _ut << std::endl;
    return _ut;
}


const Matrise Matrise::operator=(const Matrise& rhs) {
    for(int m = 0; m < størrelse; m++) {
        for(int n = 0; n < størrelse; n++) {
            this->matrise[m][n] = rhs.les(m, n);
        }
    }
    return *this;
}


const Matrise operator+(const Matrise& lhs, const Matrise& rhs) {
    Matrise arbeidsplass;
    if(lhs.dimensjon == rhs.dimensjon) {
        int lhs_strl = lhs.dimensjon;           //kortform
        for(int m=0; m < lhs_strl; m++) {
            for(int n=0; n < lhs_strl; n++) {
                double lhs_verdi = lhs.les(m, n);
                double rhs_verdi = rhs.les(m, n);
                arbeidsplass.sett(m, n, (lhs_verdi + rhs_verdi));
            }
        }
    }
    return arbeidsplass;
}



Matrise operator+=(Matrise& lhs, const Matrise& rhs) {
/*    for(int rad=0; rad < størrelse; rad++) {
        for(int kolonne=0; rad < størrelse; rad++) {
            double element  =   lhs.les(rad, kolonne)
                            +   rhs.les(rad, kolonne);
            lhs.sett(rad, kolonne, element);
        }
    }*/
    lhs = lhs + rhs;
    return lhs;
}


//Mathias! Kom tilbake hit og fiks!
const Matrise operator-(const Matrise& lhs, const Matrise& rhs) {
    Matrise arbeidsplass;
    if(lhs.dimensjon == rhs.dimensjon) {
        int lhs_strl = lhs.dimensjon;
        for(int m=0; m < lhs_strl; m++) {
            for(int n=0; n < lhs_strl; n++) {
                double lhs_verdi = lhs.les(m, n);
                double rhs_verdi = rhs.les(m, n);
                arbeidsplass.sett(m, n, (lhs_verdi - rhs_verdi));
            }
        }
    }
    return arbeidsplass;
}


Matrise operator-=(Matrise& lhs, const Matrise& rhs) {
    /*for(int rad=0; rad < størrelse; rad++) {
        for(int kolonne=0; rad < størrelse; rad++) {
            double element  =   lhs.les(rad, kolonne)
                            -   rhs.les(rad, kolonne);
            lhs.sett(rad, kolonne, element);
        }
    }*/
    lhs = lhs - rhs;
    return lhs;
}


//Note to self : Dette burde du kunne template
//..men.. men.. tid! TIIIID!
const Matrise operator*(const Matrise& lhs, const Matrise& rhs) {
    Matrise arbeidsplass(0, 0, 0, 0);


    for(int m = 0; m < størrelse; m++) {
        for(int n = 0; n < størrelse; n++) {
            for(int i = 0; i < størrelse; i++) {
                arbeidsplass.matrise[m][n]  +=  lhs.les(m, i)
                                            *   rhs.les(i, n);
            }
        }
    }


    return arbeidsplass;
}


const Matrise operator*(const int& lhs, const Matrise& rhs) {
    Matrise arbeidsplass;
    for(int m = 0; m < størrelse; m++) {
        for(int n = 0; n < størrelse; n++) {
            arbeidsplass.sett(m, n, (lhs*rhs.les(m, n)));
        }
    }
    return arbeidsplass;
}


Matrise operator*=(Matrise& lhs, const Matrise& rhs) {
    lhs = lhs * rhs;
    return lhs;
}



/*
Note: Oppgaveteksten foreslår å utvide til feilhåndtering seinere i kurset når
unntak endelig blir dekket. Woo.

Note: Husk nå endelig at c++ ikke bruker exceptions som legitime kontrollstrukturer.
Throwing exceptions is - apparently - a bad thing.
i
-Trenger ikke overloade =
-"exceptions i c++ er når det er _virkelig_ exceptional"
-
*/

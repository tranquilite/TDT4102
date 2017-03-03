#include<iostream>
#include<utility>

#include"matrix.h"

#define DEBUG


Matrix::Matrix() {
    this->matrise = nullptr;
    #ifdef DEBUG
        std::cout << "\n\tUgyldig matrise opprettet\n";
    #endif
}

Matrix::Matrix(int rader, int kolonner) {
    this->rader = rader;
    this->kolonner = kolonner;
    this->matrise = new double*[rader];
    for(int M=0; M < rader; M++) {
        this->matrise[M] = new double[kolonner];
        for(int N=0; N < kolonner; N++) {
            matrise[M][N] = 0.0;
        }
    }
    #ifdef DEBUG
        std::cout << "\n\tNullmatrise opprettet\n";
    #endif
}

Matrix::Matrix(int rader) : Matrix(rader, rader) {
    this->rader = rader;
    for(int M=0; M < rader; M++) {
        this->matrise[M] = new double[rader];
        this->matrise[M][M] = 1.0;
    }
    #ifdef DEBUG
        std::cout << "\n\tIdentitetsmatrise opprettet\n";
    #endif
}

Matrix::Matrix(const Matrix& rhs) {
    this->rader = rhs.getHeight();
    this->kolonner = rhs.getWidth();
    this->matrise = new double*[rader];
    for(int M=0; M < rader; M++) { //copypasta fra Matrix(int, int);
        this->matrise[M] = new double[kolonner];
        for(int N=0; N < kolonner; N++) {
            matrise[M][N] = rhs.get(M,N);
        }
    }
    #ifdef DEBUG
        std::cout << "\n\tKopimatrise opprettet\n";
    #endif
}

Matrix::~Matrix() {
    delete this->matrise;
    this->matrise = nullptr;
}

double Matrix::get(int rad, int kolonne) const {
    return this->matrise[rad][kolonne];
}

void Matrix::set(int rad, int kolonne, double verdi) {
    this->matrise[rad][kolonne] = verdi;
}

int Matrix::getHeight() const { return this->rader; }
int Matrix::getWidth()  const { return this->kolonner; }
bool Matrix::isValid() const  { return (this->matrise != nullptr); }

Matrix Matrix::operator=(Matrix& rhs) { // deep copy av høyre side
    //Fuckings magi. Forstår ikke den dritt av dette. Les opp og lær.
    std::swap(matrise, rhs.matrise);
    return *this;
    //nisse.
}  // rhs blir destruert

Matrix Matrix::operator+=(const Matrix& rhs) {
    if(isValid() && rhs.isValid() &&
        this->rader == rhs.getHeight() &&
        this->kolonner == rhs.getWidth() ) {
        Matrix t = rhs;
        for(int m=0; m < rader; m++) {
            for(int n=0; n < kolonner; n++) {
                matrise[m][n] += t.matrise[m][n];
            }
        }

    } else { *matrise = nullptr; }

    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) {
    //vitass foreslår:
    /*
    //siden (lhs + rhs) = et helt annet objekt, som ikke
    //skal påvirke (lhs) || (rhs), så..
    Matrix m(*this);    //lag kopi av lhs
    m += rhs;           //antar += er overloaded
    return m;           //returner kopien
    //fordel: bygger på forrige overload, reduserer kodeduplisering.
    */
    Matrix eh = *this;
    
    if(isValid() && rhs.isValid() &&
        this->rader == rhs.getHeight() &&
        this->kolonner == rhs.getWidth() ) {
        Matrix t = rhs;
        for(int m=0; m < rader; m++) {
            for(int n=0; n < kolonner; n++) {
                // IKKE matrise[m][n] += ...
                eh.matrise[m][n] += t.matrise[m][n];
                //nisse
            }
        }

    } else { *matrise = nullptr; }

    return eh;
}

const std::ostream& operator<<(std::ostream& stream, const Matrix& M) {
    for(int i=0; i < M.getHeight(); i++) {
        for(int e=0; e < M.getWidth(); e++) {
            stream << M.get(i, e) << " ";
        }
    stream << std::endl;
    }
    return stream;
}

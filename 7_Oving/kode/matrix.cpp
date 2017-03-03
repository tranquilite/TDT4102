#include<iostream>

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

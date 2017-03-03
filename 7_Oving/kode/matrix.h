#include<iostream>

#pragma once

class Matrix {
    private:
        //   M    x    N
        int rader, kolonner;
        double **matrise;

    public:
        Matrix();
        Matrix(int rader, int kolonner);
        explicit Matrix(int rader);
        ~Matrix();
        Matrix(const Matrix& rhs);

        int getHeight() const;
        int getWidth() const;
        bool isValid() const;
        double get(int rad, int kol) const;
        void set(int rad, int kol, double verdi);

        Matrix operator=(Matrix& rhs);
        Matrix operator+=(const Matrix& rhs);
        Matrix operator+(const Matrix& rhs);

};

const std::ostream& operator<< (std::ostream&, const Matrix& M);

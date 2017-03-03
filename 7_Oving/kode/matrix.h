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

        double get(int rad, int kol) const;
        void set(int rad, int kol, double verdi);
        

};

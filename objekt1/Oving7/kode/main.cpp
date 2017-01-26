#include<iostream>
#include<string>
#include<fstream>

#include"o7_1.cpp"
#include"o7_2.cpp"
#include"o7_3.cpp"

using std::cout;
using std::cin;
using std::string;
using std::ofstream;

int ord_til_fil();
int lag_fil_linjenummer();
void tegnstatistikk();
void ordstatistikk();
void meny();

int main() {
    //meny();
    ordstatistikk();
    return 0;
}

void meny() {
    int valg = 99;
    bool rage_quit = false;
    while(!rage_quit) {
        cout    << "1 for 1a\n"
                << "2 for 1b\n etc..\n"
                << "0 for /part\n";
        cin >> valg;
        switch(valg) {
            case 0: cout<< "Går hjem.."; rage_quit = true; break;
            case 1: cout<< "Ord_Til_Fil..\n"; ord_til_fil(); break;
            case 2: cout<< "Linjenummer..\n"; lag_fil_linjenummer(); break;
            case 3: cout << "Tegnstats\n"; tegnstatistikk(); break;
        }
    }
}

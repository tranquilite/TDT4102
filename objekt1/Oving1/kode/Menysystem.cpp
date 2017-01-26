#include<iostream>
using namespace std;


int inputInteger();
void inputIntegersUsingLoopAndPrintSum();
double inputDouble();
void NOKtEUR();


void tableDeMultiplication() {
    int kol = 10, rad = 10;
    cout << "Tabellbredde (kolonner): ";
    cin >> kol;
    cout << "Tabellhøyde (rader):  \t";
    cin >> rad;
    for(int r = rad; r > 0; r--) {
        for(int c = 1; c <= kol; c++) {
            cout << r*c << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int valg;
    while(true) {
        cout << "\nVelg funksjon:\n"
             << "0) Avslutt.\n"
             << "1) Summer to tall.\n"
             << "2) Summer flere tall.\n"
             << "3) Konverter NOK til EURO.\n"
             << "4) Gangetabell.\n"
             << "Angi valg(0-4): ";
        cin  >> valg;
        switch(valg) {
            case 0:
                return 0;
            case 1:
                int smeg;
                smeg = inputInteger() + inputInteger();
                cout << "Summen av to tall: " << smeg << endl;
                break;
            case 2:
                inputIntegersUsingLoopAndPrintSum();
                break;
            case 3:
                NOKtEUR();
                break;
            case 4:
                tableDeMultiplication();
                break;
        }
    }
    return 0;
}


int inputInteger() {
    int a = 0;
    cout << "Skriv in et tall: ";
    cin >> a;
    return a;
}


void inputIntegersUsingLoopAndPrintSum() {
    int sum = 0, res = 0;
    cout << "Summerer i vei! Tast 0 for å stikke til samfundet.\n";
    do {
        res = inputInteger();
        sum += res;
    }
    while(res != 0);
    cout << "Summen er: " << sum << endl;
}


double inputDouble() {
    double b = 0;
    cout << "Skriv inn et tall: ";
    cin >> b;
    return b;
}

void NOKtEUR() {
    double nok = 0, eur = 0;
    do{
        nok = inputDouble();
        //DETTE ER JUKS!
        printf("Det burde bli %.2f euro\n", (nok/(9.12)));
    } while(!(nok > 0));
}

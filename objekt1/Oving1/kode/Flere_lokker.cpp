#include<iostream>
using namespace std;


// Oppgave 5
void calculateLoanPayments() {
    double lan = 10000;
    double rente = 10;
    double gjeld = 0, innbet;
    cout    << "Hvor mye vil du låne? ";
    cin     >> lan;
    cout    << "Til hvilken rente? ";
    cin     >> rente;
    gjeld = lan;
    cout << "År\tInnbetaling\tGjeld" << endl;
    for(int i=1; i <= 10; i++) {
        innbet = (lan/10) + ((rente/100)*gjeld);
        gjeld = gjeld - (lan/10);
        cout << i << "\t" << innbet << "\t\t" << gjeld << endl;
    }

    return;
}

int main() {
    while(true) {
        calculateLoanPayments();
    }
    return 0;
}

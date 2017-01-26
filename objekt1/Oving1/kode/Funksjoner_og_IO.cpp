#include<iostream>
using namespace std;
//Fordi std er kult.
// Neida. Jeg er bare lat. Herregud. 5 ekstra tegn.

//1A
void inputAndPrintInteger() {
    int a = 0;
    cout << "Skriv inn et tall: ";
    cin >> a;
    cout << "Du skreiv: " << a;
}


int inputInteger() {
    int a = 0;
    cout << "Skriv inn et tall: ";
    cin >> a;
    return a;
}


void inputIntegersAndPrintSum() {
    int a = inputInteger()+inputInteger();
    cout << "Summen av tallene: " << a;
}


bool isOdd(int n) {
    if( n % 2 == 0 ) {
        return false;
    }
    return true;
}


void humanReadableTime(int s) {
    //DENNE ER SÅ UTROLIG STYGG!
    // 10000 sec 2t, 46m, 40s
    int t = 0, m = 0;
    t = (s / 3600);
    s = s - t*3600;
    m = (s / 60);
    s = s - m*60;

    if(t > 0) { cout << t << " time"; }
    if(t > 1) { cout << "r"; }
    if(m > 0) { if(t>0) { cout << ", "; } cout << m << " minutt"; }
    if(t > 1) { cout << "er"; }
    if(s >= 0) { if(t>0 or m > 0) { cout << " og "; } cout << s << " sekund"; }
    if(s > 1) { cout << "er\n"; }

}


int main() {
    cout << "1 - Funksjoner og IO\n";
    cout << "1A: \n";
    inputAndPrintInteger();
    
    cout << "\n \n 1B: \n";
    int heltall = inputInteger();
    cout << "Du skreiv: " << heltall << endl;
    
    cout << "\n \n 1C: \n";
    inputIntegersAndPrintSum();

    cout << "\n \n 1D: MAGISK! borte. Se kildekode.\n";
    /* Brukte inputInteger, fordi superlat. To funksjonskall.
    uimponerende, men problemet er trivielt.
    nevermind at oppgaven sa at funksjonen bare skulle skrive
    til konsollen, så jeg implementerte inputAndPrintInteger()
    som en void-type. */

    cout << "\n \n 1E: \n";
    for(int i=10; i < 15; i++) {
        if(isOdd(i)) {
            cout << i << " er et oddetall\n";
        } else {
            cout << i << " er et partall\n";
        }
    }
    

    cout << "\n \n 1F: \n";
    humanReadableTime(10000);
    return 0;
}

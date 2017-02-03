#include <iostream>
#include <iomanip>

using namespace std;

// Følgende fire funksjoner konverterer celsius til fahrenheit,
// de bruker forskjellige kombinasjoner av
// - input fra bruker/funksjonsargument
// - skrive ut til skjerm/returnere

// Ta input fra bruker og skriv ut til skjerm
void fahrenheitPrint() {
    double celsius;
    cout << "Skriv inn antall grader celsius: ";
    cin >> celsius;
    double fahrenheit = celsius * 1.8 + 32;
    cout << "Det tilsvarer: " << fahrenheit << " fahrenheit." << endl;
}

// Ta inn celsius som argument og skriv ut til skjerm
void fahrenheitPrint(double celsius) {
    double fahrenheit = celsius * 1.8 + 32;
    cout << "Det tilsvarer: " << fahrenheit << " fahrenheit." << endl;
}

// Ta input fra bruker og returner resultat
double fahrenheitReturn() {
    double celsius;
    cout << "Skriv inn antall grader celsius: ";
    cin >> celsius;
    double fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}

// Ta inn celsius som argument og returner resultat
double fahrenheitReturn(double celsius) {
    double fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}

// Eksamen vår 2016, oppgave 2b -- noe modifisert

void weatherInfo(int id, double wind, int dir) {
    cout << "INFO " << id << ": ";
    cout << fixed << setprecision(2) << wind << " fra ";

    if (dir >= 45 && dir <= 134) {
        cout << "Øst";
    }
    else if (dir >= 135 && dir <= 224) {
        cout << "Syd";
    }
    else if (dir >= 225 && dir <= 314) {
        cout << "Vest";
    }
    // Oppgaven spesifiserer at argumentet dir er et heltall i intervallet [0,359]
    // så vi kan anta at funksjonen ikke får input utenfor dette intervallet
    else {
        cout << "Nord";
    }
    cout << endl;
}

int main() {
    return 0;
}

/*
TDT4102 - Prosedyre- og Objektorientert programmering
Øving 1
*/

#include<iostream>
#include<cmath>
#include<string>


using namespace std;

//Opg. 1
void inputAndPrintInteger();
void inputIntegersAndPrintSum();
void humanReadableTime(int);
int inputInteger();
void opg1();
bool isOdd(int);
//Opg. 2
void inputIntegersUsingLoopAndPrintSum();
void NOKtEUR();
double inputDouble();
void opg2();
//Opg. 3
void tableDeMultiplication();
//Opg. 4
double discriminant(double, double, double);    //prototype
void printRealRoots(double, double, double);    //prototype
void solveQuadraticEquation();
//Opg. 5
void calculateLoanPayments();


int main() {
    int valg;
    while(true) {
        cout    << "\nVelg funksjon:\n"
                << "0) Avslutt.\n"
                << "1) Summer to tall.\n"
                << "2) Summer flere tall.\n"
                << "3) Konverter NOK til EURO.\n"
                << "4) Gangetabell.\n"
                << "5) Andregradslikninger.\n"
                << "6) Lånekalkulator.\n"
                << "Angi valg(0-6): ";
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
            case 5:
                solveQuadraticEquation();
                break;
            case 6:
                calculateLoanPayments();
        }
    }
    return 0;
}


//1A
void inputAndPrintInteger() {
    int a = 0;
    cout << "Skriv inn et tall: ";
    cin >> a;
    cout << "Du skreiv: " << a;
    return;
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
    return;
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
    if(s >= 0) { if(t>0 or m > 0) { cout << " og "; } cout << s << "sekund"; }
    if(s > 1) { cout << "er\n"; }
    return;
}


void opg1() {
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
    return;
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
    return;
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
    return;
}


void opg2() {
    cout << "2 - Løkker\n";
    cout << "2A:\n";
    inputIntegersUsingLoopAndPrintSum();

    cout << "\n\n2B: - Magisk kommentar! Se kildekode\n";
    /* Do-While vs. While. I tilfellet 0-exit, så trenger du at
    koden kjøres minst èn gang, så Do-While. Alternativet er en
    while-løkke, hvor du setter taket på forhånd, og sjekker om
    den skal kjøre før du fyrer i vei.
    int grense, sum = 0; cout << "Hvor mange? "; cin << grense;
    while(int i=0; i < grense; i++) { sum += inputInteger() }
    Kodekommentering er min gråstein. Folk er ute og pilser.
    Jeg var invitert! JEG! Og hva gjør jeg? Sitter på hovedbygget
    og skriver dette.
    "Hvor farsken ble livet ditt av?
    Livskvaliteten din er altfor lav.
    Så for en gangs skyld, nigga, stress litt ned"*/

    cout << "\n\n2C:\n";
    //double dobbel. wow. Maksimalt uoversiktlig.
    double dobbel = inputDouble();
    cout << "Du skreiv: " << dobbel << endl;

    cout << "\n\n2D:\n";
    NOKtEUR();

    cout << "\n\n2E: - Kommentaroppgave. Se kildekode\n";
    /*Det er litt kleint. Vi bør ikke bruke inputInteger, fordi
    inputInteger jobber med heltall. Det er litt der. De to
    valutastørrelsene har en lei tendens til å være representert
    med fraksjoner i tillegg til heltall. int-typen er ikke akkurat
    utstyrt for å representere fraksjoner, så, flyttall.
    "Kommenter også returtypen du *skreiv* i forrige oppgave."
    Siden tendensen hittil har vært å eksplisitt nevne når en
    funksjon returnerer eller skriver, og forrige oppgave ikke
    nevnte at noe skulle mates tilbake, så, magisk. Void.
    Hvis det skulle noe tilbake, så ville det vært double.
    "Men funksjonen din slutter jo hvis jeg ikke taster inn et tall"
    Ja? Oppgaveteksten lyder at hvis (antar *hviss*), det kommer
    et negativt tall, så skal programmet spørre på nytt.
    0 er ikke negativt.*/
    return;
}


// Oppgave 3
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
    return;
}

// Oppgave 4

double discriminant(double a, double b, double c) {
    double disk;                //initialiser
    disk = pow(b,2) - 4*a*c;    //når vi først har lastet cmath
    return disk;                //returner
}


void printRealRoots(double a, double b, double c) {
    double root1, root2;
    double disk = discriminant(a, b, c);
    if(disk < 0) {                                  // b^2 - 4ac < 0
        cout << "Likningen har ingen løsning\n";    // Nu er det min arbeidslyst
        return;                                     // som forlater skrivebordet
    } else if(disk == 0) {                          //(likeså forlater vi rutinen)
        root1 = ((-1)*b)/2*a;                       //hvis b^2 == 4ac
        cout << "Likningen har én løsning: " << root1 << endl;
    } else if(disk > 0) {
        root1 = ((-1)*b + sqrt(disk))/2*a;
        root2 = ((-1)*b - sqrt(disk))/2*a;
        cout << "Mulig at likningen har to løsninger: " << root1
             << " og " << root2 << endl;
    } else {
        cout << "Dette burde ikke skje.\n\n";     //Fail-deadly
    }    

    return;                                         //se php og die()
}

void solveQuadraticEquation() {
    double a = 1, b = 1, c = 1;
    cout << "Gitt en andregradsuttrykk av formen ax^2 + bc + c, oppgi verdier "
         << "for a, b, og c\n " << "a = ";          // vi antar .. prior
    cin  >> a;                                      // knowledge
    cout << "b = ";
    cin  >> b;
    cout << "c = ";
    cin  >> c;

    printRealRoots(a, b, c);
    return;
}

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

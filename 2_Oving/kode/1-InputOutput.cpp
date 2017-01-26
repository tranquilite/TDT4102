#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;

//1
void inputAndPrintInteger();
int inputInteger();
void inputIntegersAndPrintSum();
bool isOdd(int);
void testIsOdd();
void printHumanReadableTime(int);
//2
void inputIntegersUsingLoopAndPrintSum();
double inputDouble();
void NOKtEUR();
//3
void tableDeMultiplication();
//4
double discriminant(double, double, double);
void printRealRoots(double, double, double);
void solveQuadraticEquation();
//5
void calculateLoanPayments();


int main() {
    // 3 - MENYER
    // Men vi er late. Ev kunne man laget en løkke
    //som går gjennom et streng-array med alt som skal printes ut.
    //men det virker uhensiktsmessig knotete for situasjonen.
    // string arrMeny[] = { "\nVelg funksjon:\n" ... };
    // for(int lineF = 0; lineF < sizeof(arrMeny)/sizeof(arrMeny[0]);
    // linef++) { cout << arrMeny[lineF]; }
    // eller noe
    int valg;
    while(true) {
        cout << "\nVelg funksjon:\n"
             << "0) Avslutt.\n"
             << "1) Summer to tall.\n"
             << "2) Summer flere tall.\n"
             << "3) Konverter NOK til EURO.\n"
             << "4) Gangetabell.\n"
             << "5) Løsne på kvadrater.\n"
             << "6) Låneavtalegreie.\n"
             << "Angi valg(0-5):";
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
                break;
        }
    }
    return 0;
}

void inputAndPrintInteger() {
    int n = 0;
    cout << "Skriv inn et tall: ";
    cin >> n;
    cout << "Du skrev: " << n;
}

int inputInteger() {
    //Foretrukket over inputAndPrintInteger; slipper unødvendig knudd, sia
    //den lettere brukes på nytt med annet crap.
    int n = 0;
    cout << "Skriv inn et tall: ";
    cin >> n;
    return n;
}

void inputIntegersAndPrintSum() {
    //Bruker inputInteger() fordi den returnerer, og aritmetikken blir
    //lettere vanskelig å impe uten å skrive hele inputAndPrintInteger()
    //på nytt. ev. lese cout før den går til skjermbufferen, siden lengda på
    //teksten før heltallet er kjent.
    int e_ = inputInteger();
    cout << (inputInteger() + e_) << endl;
}

bool isOdd(int n) {
    if (n % 2 != 0) {
        return true;
    } else { //eksplisitt er bedre enn implisitt
        return false;
    }
    return false; //"Errors never pass silently"
}

void testIsOdd() {
    for (int i = 1; i < 15; i++) {
        if (isOdd(i)) {
            cout << i << " er et oddetall" << endl;
        } else {
            cout << i << " er et partall" << endl;
        }
    }
}

void printHumanReadableTime (int s) {
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

// 2 - LØKKER

void inputIntegersUsingLoopAndPrintSum() {
    /*Do-While vs While. I tilfellet 0-exit må løkka kjøre minst en gang.
    alternativet blir en while-løkke med et forhåndssatt antall loops
    før den fyrer i vei. Type
    int grense, sum = 0; cout << "Hvor mange? "; cin << grense;
    while(int i=0; i < grense, i++) { sum += inputInteger(); }
    og så bare Hvor ble livet ditt av
    livskvaliteten din er altfor lav
    så for en gangs skyld niggah stress litt ned */
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
    //Foretrukket over inputAndPrintInteger; slipper unødvendig knudd, sia
    //den lettere brukes på nytt med annet crap.
    double n = 0;
    cout << "Skriv inn et tall: ";
    cin >> n;
    return n;
}


void NOKtEUR() {
    //og vi bruker double fordi, hvem vet. Kanskje matcher ikke NOK-EUR
    //slik at det ikke er heltallsparitet mellom NOK og EUR.
    //Bra vi bruker flyttall med dobbel presisjon! Sånn at vi får det nøyaktig
    //hvis vi skulle jobbet med mikrotransaksjoner i tusentallsvolum
    double nok = 0;
    do{
        nok = inputDouble();
        //DETTE ER JUKS!
        // ..og egentlig er det dårlig praksis. burde vært type
        // double eur = 9.64; og så (nok/eur). Unngå const midt i.
        printf("Det burde bli %.2f euro\n", (nok/(9.64)));
    } while(!(nok > 0));
}

//3 - MENYSYSTEM
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

//4 - Funksjoner i funksjoner og rotfrukter
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
        cout << "Dette burde ikke skje.\n\n";     //Fail-deadly.
    }    

    return;
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
}

//4 - Flere løkker : Return of the schwoop
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

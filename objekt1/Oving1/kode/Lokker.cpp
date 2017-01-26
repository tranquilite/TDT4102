#include<iostream>
#include<stdio.h>
using namespace std;


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


int main() {
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
}

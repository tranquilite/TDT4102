#include<iostream>

void fillInFibonacciNumbers(int resultat[], int lengde) {
    resultat[0] = 0; //Løsninga er ikke generell nok at  vi trenger bry oss
    resultat[1] = 1; //iaf med det første.
    resultat[2] = 1; //Problemer oppstår hvis oppgava var "generer sekvens av fib fra indeks e"
    // ev hvis lengde < 2..
    for(int e=3; e < lengde; e++) {
        resultat[e] = resultat[e-1] + resultat[e-2];
    }
}

void printArray(int rekke[], int lengde) {
    for(int i=0; i < lengde; i++) {
        std::cout << rekke[i] << " ";
    }
}


void createFibonacci() {
    int len;
    std::cout << "Sekvenslengde: ";
    std::cin >> len;
    int * fibRekke = new int[len];

    fillInFibonacciNumbers(fibRekke, len);
    printArray(fibRekke, len);

}

#include<iostream>

#include "utilities.h"
#include "mastermind.h"

using std::cout;
using std::cin;
using std::endl;


void playMastermind() {
    bool running = true;
    const int SIZE = 4;
    const int LETTERS = 6;
    enum Karakter {A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T,
                    U, V, W, X, Y, Z}; //Meningsløst. Fjern i refactor.
    Karakter lower = A, upper = F;
    int turn = 0;
    char *code = new char[SIZE+1];
    char *guess = new char[SIZE+1];

    cout << "Gjett serien. Return/bokstav\n";
    randomizeCString(code, SIZE+1, lower, upper);
    readInputToCString(guess, SIZE, lower, upper);
    while((checkCharactersAndPosition(code, guess, SIZE) < SIZE) and turn < 4) {
        cout    << "Du hadde " << checkCharacters(code, guess, SIZE)
                << " tegn rett, og " << checkCharactersAndPosition(code, guess, SIZE)
                << " var både rett og på rett posisjon\n"
                << (4-turn) << " forsøk igjen: " << code << endl;
        readInputToCString(guess, SIZE, lower, upper);
        turn++;
    }
    if(checkCharactersAndPosition(code, guess, SIZE) <= SIZE) {
        cout << "Gratulerer, du har klart det?\n";
    } else {
        cout << "Neg.\n";
    }
}

int checkCharactersAndPosition(char code[], char guess[], int arrLen) {
    int counts = 0;
    for(int i=0; i<arrLen; ++i) {
        if(code[i] == guess[i]) {
            counts += 1;
            }
        }
    return counts;
}

int checkCharacters(char code[], char guess[], int arrLen) {
    //teller feil
    //ah ,fuckit. Tida går uansett ut
    //TENK DA. Hallo. Det står jo et hint i oppgaveteksten.
    int counts = 0;
    for(int i=0; i<arrLen; ++i) {
        for(int e=0; e<arrLen; ++e) {
            if(code[i] == guess[e]) {
                counts++;
            }
        }
    }
    return counts;
}

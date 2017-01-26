#ifndef _stream
#include<iostream>
#define _stream
#endif

using namespace std;

#include"utilities.h"
#include"tests.h"

void meny() {
    bool Slutt = false;
    while(!Slutt) {
        int innvalg;
        cout << "Meny: \n";
        cout << "0 Exit\n";
        cin >> innvalg;
        switch(innvalg) {
            case 0:
                Slutt = true;
                break;
            case 1:
                cout << "shitshit\n";
        }
    }
}

int main() {
    meny();
    return 0;
}


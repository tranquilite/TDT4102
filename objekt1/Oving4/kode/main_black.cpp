#include<iostream>

#include"enums.h"
#include"kortklasse.h"
#include"kortstokk.h"


int main() {

    CardDeck OST;
    OST.print_short();
    OST.shuffle();
    OST.print_short();
    return 0;
}

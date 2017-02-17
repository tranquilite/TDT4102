#include<iostream>

using std::cout;

#include"Card.h"
#include"CardDeck.h"
#include"Blackjack.h"


int main() {
    //Card SexyTimes(CLUBS, ACE);
    //cout << SexyTimes.toStringShort();

    CardDeck bollemus;
    std::cout << bollemus.drawCard().toString();

    BlackJack blackjack;
    blackjack.playGame();
    cout << std::endl << std::endl;
    return 0;
}

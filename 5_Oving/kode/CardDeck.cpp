#include<iostream>
#include<ctime>
#include<cstdlib>

#include "Card.h"
#include "CardDeck.h"

CardDeck::CardDeck() {
    srand(time(0));
    this->currentCardIndex = 0;
    
    for(int i=0; i < 4; i++) {
        for(int e=2; e < 15; e++) {
            Card dette_kortet(static_cast<Suit>(i), static_cast<Rank>(e));
            this->cardsInDeck.push_back(dette_kortet);
        }
    }
    this->shuffle();
}

void CardDeck::print() {
    for (Card printCard : this->cardsInDeck) {
        std::cout << printCard.toString() << std::endl;
    }
}

void CardDeck::printShort() {
    for (Card printCard : this->cardsInDeck) {
        std::cout << printCard.toStringShort() << std::endl;
    }
}

void CardDeck::swap(int a, int b) {
    Card pausekort = cardsInDeck[a];
    cardsInDeck[a] = cardsInDeck[b];
    cardsInDeck[b] = pausekort;
}

void CardDeck::shuffle() {
    for(int i=0; i < 51; i++) {
        int a = this->randomWithLimits(0, 51), b = this->randomWithLimits(0,51);
        swap(a, b);
    }
}

int CardDeck::randomWithLimits(int lower, int upper) {
    int rekkevidde_diff = (upper - lower);
    return ((rand() % rekkevidde_diff) +lower);
}

Card CardDeck::drawCard() {
    Card returnCard = cardsInDeck[currentCardIndex];
    currentCardIndex++;
    return returnCard;
}

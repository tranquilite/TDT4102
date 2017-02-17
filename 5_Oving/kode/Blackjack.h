#pragma once

#include "Card.h"
#include "CardDeck.h"

class BlackJack {
    private:
        CardDeck deck;
        int playerHand; //Sum av hånden
        int dealerHand; //Sum av hånden
        int playerCardsDrawn;   //Sum antall kort trukket
        int dealerCardsDrawn;   //Sum antall kort trukket

    public:
        bool isAce(Card* kortTest);
        int getCardValue(Card* kort);
        int getPlayerCardValue(Card* kort);
        int getDealerCardValue(Card* kort, int STPred);
        bool askPlayerDrawCard();
        void drawInitialCards();
        void playGame(); //NEG. fgsfds
};


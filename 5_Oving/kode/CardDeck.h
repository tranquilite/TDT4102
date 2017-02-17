#pragma once

#include<vector>

#include "Card.h"

class CardDeck {
    private:
        std::vector<Card> cardsInDeck;
        int currentCardIndex;
        void swap(int a, int b);
        int randomWithLimits(int lower, int upper);

    public:
        CardDeck();
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};

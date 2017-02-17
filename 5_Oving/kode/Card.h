#pragma once

#include <string>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct CardStruct {
    Suit s;
    Rank r;
};

//char* suitToString(Suit __suit);
//const char* rankToString(Rank __rank);
std::string suitToString(Suit __suit);
std::string rankToString(Rank __rank);
std::string toString(CardStruct __card);
std::string toStringShort(CardStruct __card);


class Card {
    private:
        Suit s;
        Rank r;
        bool invalid;

    public:
        Card();
        Card(Suit s, Rank r);
        void initialize(Suit _s, Rank _r);
        Suit getSuit();
        Rank getRank();
        std::string toString();
        std::string toStringShort();
};

#pragma once
#ifndef i_enum
#define i_enum
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

enum Rank {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK = 15, QUEEN, KING, ACE};

struct Cardstruct {
    Suit suit;
    Rank rank;
};
#endif

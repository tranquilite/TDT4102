#pragma once
#include"enums.h"
#include"kortklasse.h"

class CardDeck {
public:
    void        print() const;
    void        print_short() const;
    void        shuffle();
    void        draw_card();
    CardDeck();
    ~CardDeck();
private:
    Card*       cards[52];
    int         __current_card_index;
    void        swap(int, int);
};

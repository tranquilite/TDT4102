#pragma once
#include"enums.h"
#include"kortklasse.h"
#include"kortstokk.h"

class BlackJack {
public:
    int     get_card_value(Card*) const;
    bool    is_ace(Card*) const;
    int     get_player_card_value(Card*) const;
    int     get_dealer_card_value(Card*, int) const;
    bool    ask_player_draw_card() const ;
    void    play_game();

private:
    CardDeck deck;
};

#include"enums.h"
#include"kortklasse.h"
#include"kortstokk.h"
#include"blackjack.h"


int BlackJack::get_card_value(Card* kort) const {
    if( (*kort).get_rank() == ACE ) {
        return -1;
    } else {
        //Kom tilbake og fiks denne senere.
        return std::stoi(std::to_string( (*kort).get_rank() ) );
    }
}


bool BlackJack::is_ace(Card* kort) const {
    if( (*kort).get_rank() == ACE) {
        return true;
    } else {
        return false;
    }
}


int BlackJack::get_player_card_value(Card* kort) const {
    return 1;
}


int BlackJack::get_dealer_card_value(Card* kort, int hand) const {
    return 1;
}


bool BlackJack::ask_player_draw_card() const {
    return true;
}


void BlackJack::play_game() { }

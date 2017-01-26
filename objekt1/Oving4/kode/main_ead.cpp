#include<iostream>

#include"enums.h"
#include"enums_and_structs.h"

int main() {
    //Buuuuurde virkelig lage en løkke for denne. Gjør testen, du vet
    //.. "pen".
    // heh. "test".
    std::cout << suit_to_string(CLUBS)      << std::endl;
    std::cout << suit_to_string(DIAMONDS)   << std::endl;
    std::cout << suit_to_string(SPADES)     << std::endl;
    std::cout << rank_to_string(TWO)        << std::endl;
    std::cout << rank_to_string(QUEEN)      << std::endl;
    std::cout << rank_to_string(NINE)       << std::endl;

    Cardstruct derp;
    derp.suit = CLUBS;
    derp.rank = ACE;
    std::cout << to_string(derp)            << std::endl;
    std::cout << to_string_short(derp)      << std::endl;

    return 0;
}

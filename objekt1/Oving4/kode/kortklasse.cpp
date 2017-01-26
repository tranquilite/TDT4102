#include<iostream>
#include<string>
#include<locale>

#include"enums.h"
#include"kortklasse.h"


char* suit_to_string(Suit __suit) {
    char* __farge = new char[10] ;
    switch(__suit) {
        case 0:
            memcpy(__farge, "Clubs", 5);     break;
        case 1:
            memcpy(__farge, "Diamonds", 8);  break;
        case 2:
            memcpy(__farge, "Hearts", 6);    break;
        case 3:
            memcpy(__farge, "Spades", 6);    break;
        default:
            break;
        }
    return __farge;
}


const char* rank_to_string(Rank __rank) {
    const char* __verdi[] = {"\0", "\0", "Two", "Three", "Four", "Five", 
                            "Six", "Seven", "Eight", "Nine", "Ten", 
                            "Jack", "Queen", "King", "Ace"};
    return __verdi[__rank];
}


Card::Card(Suit s, Rank r) {
    //Dette må være den mest retarderte koden jeg
    //noensinne har produsert
    initialize(s, r);
}

void Card::initialize(Suit s, Rank r) {
    this->__s = s;
    this->__r = r;
    this->__invalid = false;
}

Suit Card::get_suit() const {
    return this->__s;
}

Rank Card::get_rank() const {
    return this->__r;
}


string Card::to_string() const {
    string return_streng;
    if(this->__invalid == true) {
        return_streng = "Ugyldig kort";
    } else {
        return_streng = rank_to_string(this->__r);
        return_streng.append(" of ");
        return_streng.append(suit_to_string(this->__s));
    }
    return return_streng;
}

string Card::to_short_string() const {
    string retur_streng;
    if(this->__invalid == true) {
        retur_streng = "Ugyldig kort";
    } else {
        retur_streng.append(suit_to_string(this->__s), 1);
        retur_streng.append(std::to_string(__r));
    }
    //Av alle idiotiske feil å gjøre
    //Av alt.. er det mulig?
    //Er det mulig?
    //ER DET MULIG Å VÆRE SÅ TEIT?!
    return retur_streng;
}

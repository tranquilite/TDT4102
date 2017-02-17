#include<iostream>
#include <string>
#include <locale>

using std::string;

#include "Card.h"

/*
Dette er mye kulere.. :(
char* suitToString(Suit __suit) {
    char* __farge = new char[10];
    switch(__suit) {
        case 0:
            memcpy(__farge, "Clubs", 5); break;
        case 1:
            memcpy(__farge, "Diamonds", 8); break;
        case 2:
            memcpy(__farge, "Hearts", 6); break;
        case 3:
            memcpy(__farge, "Spades", 6); break;
        default:
            break;
    }
    return __farge;
} */

string suitToString(Suit __suit) {
    string returnValue = "empty";
    switch(__suit) {
        case 0:
            returnValue = "Clubs"; break;
        case 1:
            returnValue = "Diamonds"; break;
        case 2:
            returnValue = "Hearts"; break;
        case 3:
            returnValue = "Spades"; break;
        default:
            returnValue = "Beerpong"; break;
        }
    return returnValue;
}
            

string rankToString(Rank __rank) {
    string __verdi[15] = {"\0", "\0", "Two", "Three", "Four", "Five",
                            "Six", "Seven", "Eight", "Nine", "Ten",
                            "Jack", "Queen", "King", "Ace"};
    return __verdi[__rank];
}

string toString(CardStruct __card) {
    string returnString = rankToString(__card.r);
    returnString.append(" of ");
    returnString.append(suitToString(__card.s));
    return returnString;
}

string toStringShort(CardStruct __card) {
    string returnString;
    returnString.append(suitToString(__card.s), 0, 1);
    returnString.append(std::to_string(__card.r));
    
    return returnString;
}

//Kortklasse oppgave balle

Card::Card() { this->invalid = true; }
Card::Card(Suit _s, Rank _r) {  this->initialize(_s, _r); }

void Card::initialize(Suit _s, Rank _r) {
    //Vi har constructors nøyaktig for dette.. Men neida.
    this->s = _s;
    this->r = _r;
    this->invalid = false;
}

Suit Card::getSuit() { return this->s; }
Rank Card::getRank() { return this->r; }

string Card::toString() {
    //ahahahaha du får meg ikke til å skrive alt på nytt
    CardStruct TarevatMandag;
    TarevatMandag.s = this->s, TarevatMandag.r = this->r;
    if(this->invalid == true) {
        return "Invalid card";
    } else {
        return ::toString(TarevatMandag);
    }
    return "";
}

string Card::toStringShort() {
    //Just just try and stop me!
    CardStruct ValentinsKort;
    ValentinsKort.s = this->s, ValentinsKort.r = this->r;
    if(this->invalid == true) {
        return "Invalid card";
    } else {
        return ::toStringShort(ValentinsKort);
    }
    return "";
}

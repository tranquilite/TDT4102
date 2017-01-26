#pragma once
#include<string>
#include"enums.h"

using std::string;

class Card {
public:
    void        initialize(Suit s, Rank r);
    Suit        get_suit() const;
    Rank        get_rank() const;
    string      to_string() const;
    string      to_short_string() const;
    Card() { this->__invalid = true; }
    Card(Suit s, Rank r);
    ~Card() { /*destructor*/ };
private:
    Suit        __s;
    Rank        __r;
    bool        __invalid;
};

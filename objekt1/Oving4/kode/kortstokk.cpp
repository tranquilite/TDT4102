#include<iostream>      //cout, endl
#include<cstdlib>       //rand()
#include<ctime>         //time()
#include<algorithm>     //swap()

#include"enums.h"
#include"kortklasse.h"
#include"kortstokk.h"

using std::cout;
using std::endl;


CardDeck::CardDeck() {
    //HERREGUD, MATHIAS
    int i = 0; // rekkereferanse. hacky og stygg. lat.
    for(int kort = 0; kort < 4; kort++) {
        for(int verdi = 2; verdi < 15; verdi++) {
            cards[i] = new Card(static_cast<Suit>(kort), 
                                static_cast<Rank>(verdi));
            i++;
        }
    }
    this->__current_card_index = 0;
}


CardDeck::~CardDeck() {
/*    for(int i = 0; i < 52; i++) {       // iterer over cards[]
        delete cards[i];                // og sletter objektene
    }*/
}


void CardDeck::print() const {
    //skriv ut kortnavn på formen <Rank> of <Suit>
    for(int i = 0; i < 52; i++) {
        if(cards[i] != NULL) {
            cout << (*cards[i]).to_string() << endl;
        }
    }
}


void CardDeck::print_short() const {
    //Skriv ut kortnavn på formen <S><Ra>
    for(int i = 0; i < 52; i++) {
        if(cards[i] != NULL) {
            cout << (*cards[i]).to_short_string() << " ";
        }
    }
    cout << endl;
}


void CardDeck::shuffle() {
    for(int i = 0; i < 256; i++) {
        //Følgende er mer eller mindre copypasta fra cplusplus.com.
        //struct tm __fremtid;
        //__fremtid = *localtime(NULL);
        //__fremtid.tm_hour   = 12;
        //__fremtid.tm_min    = 54;
        //__fremtid.tm_sec    = 32;
        //__fremtid.tm_mon    = 3;
        //__fremtid.tm_mday   = 1;
        //srand(difftime(time(NULL), mktime(&__fremtid)));
        srand(time(NULL));
        int __left      = rand() % 52;
        srand(19823942-i);
        int __right     = rand() % 52;
        this->swap(__left, __right);
    }
}


void CardDeck::swap(int __left, int __right) {
    //sjekk at indeksene ikke er større enn cards[]
    if(__left || __right < 52) {     
        std::swap(*cards[__left], *cards[__right]);
    } 
}

void CardDeck::draw_card() {
//trekk tilfeldig kort
    srand(time(NULL));
    int i = rand() % 51;
    (*cards[i]).to_string();
    delete cards[i];
    cards[i] = NULL;
}

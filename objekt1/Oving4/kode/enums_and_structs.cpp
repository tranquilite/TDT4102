#include<iostream>
#include<string>
#include<locale>

#include"enums.h"

using std::string;

//OH. MY. GOD.


char* suit_to_string(Suit _suit) {
    //la di da. "Suboptimalt" er ikke engang i nærheten
    //av å være dekkende.
    //Hadde noen sett dette i algdat, så hadde det
    //blitt fnising.
    char* _farge = new char[10];
    switch (_suit) {
        case 0:
            memcpy(_farge, "Clubs", 5);     break;
        case 1:
            memcpy(_farge, "Diamonds", 8);  break;
        case 2:
            memcpy(_farge, "Hearts", 6);    break;
        case 3:
            memcpy(_farge, "Spades", 6);    break;
        default:
            break;
    }
    return _farge;
}


//Siden vi nå har demonstrert at switch-bruken er en greish
//måte å håndtere den flyten på, samt at evnen til å  bruke
//den metoden er demonstrert, så anerkjenner vi at det finnes
//en løsning, og går videre med noe mindre bleh-ete
const char* rank_to_string(Rank _rank) {
    const char* _verdi[] = {"\0", "\0", "Two", "Three", "Four", "Five", "Six",
                            "Seven", "Eight", "Nine", "Ten", "Jack",
                            "Queen", "King", "Ace"};
    //Ja. Indeksering er et problem.
    return _verdi[_rank];
}


string to_string(Cardstruct _kort) {
    // Oppgaveteksten sier "[..] skal returnere en String [..]"
    // mens tidligere oppgaver sier
    // "[..]og returnerer en Streng som [..]""
    // "String" vs. "Streng".
    //const char* preposisjon[5] = {" of "};
    string return_streng = rank_to_string(_kort.rank);
    return_streng.append(" of ");
    return_streng.append(suit_to_string(_kort.suit));
    return return_streng;
}


string to_string_short(Cardstruct _kort) {
    string retur_streng;
    retur_streng.append(suit_to_string(_kort.suit), 1);
    retur_streng.append(std::to_string(_kort.rank));
    return retur_streng;
}

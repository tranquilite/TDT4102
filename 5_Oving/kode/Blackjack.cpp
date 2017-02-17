#include<iostream>

#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

using std::endl;
using std::cout;
using std::cin;

bool BlackJack::isAce(Card* kortTest) {
    //Hvis du ser en struktur som dette:
    if(kortTest->getRank() == ACE) {
        return true; }
    return false;
    //Refactor til :
    //return (kortTest->getRank() == ACE);
}

int BlackJack::getCardValue(Card* kort) {
    int verdi = kort->getRank();
    if (verdi == 14) {
        return -1;
    }
    else if(verdi == 11 || verdi == 12 || verdi == 13) {
        return 0;
    }
    return verdi;
}

int BlackJack::getPlayerCardValue(Card* kort) {
    int verdi = getCardValue(kort);
        if(verdi == -1){ std::cout << "Tellern for 1 eller 11?" << std::endl;
            int __brukerInn = 0;
            while(true) {
                std::cin >> __brukerInn;
                if (__brukerInn==1 or __brukerInn==11) { verdi = __brukerInn; break;}
                else { std::cout << "Kan bare ha verdi 1 eller 11" << std::endl; }
        }
    }
    return verdi;
}

int BlackJack::getDealerCardValue(Card *kort, int STPred) {
  int verdi = getCardValue(kort);
  if(verdi == -1) {
    if((STPred + 11) > 21) {
      verdi=1;
    }
    else {
      verdi=11;
    }
  }
  return verdi;
}

bool BlackJack::askPlayerDrawCard() {
    int __brukerInn;
    while(true) {
    cout << "Nytt kort? 0=Nei, 1=Ja"; cin >> __brukerInn;
    if(__brukerInn == 1 || __brukerInn == 0) {
        return static_cast<bool>(__brukerInn); }
    }
    return false;
}

/*
void BlackJack::drawInitialCards() {
    

*/
void BlackJack::drawInitialCards() {
    deck.shuffle();
    Card *p, *q;
    Card temp1 = deck.drawCard();
    Card temp2 = deck.drawCard();
    p = &temp1;
    q = &temp2;
    cout << "1. kort: "<< p->toString() << endl;
    cout << "2. kort: " << q->toString() << endl;
    this->playerHand = getPlayerCardValue(p);
    this->playerCardsDrawn++;
    this->playerHand += getPlayerCardValue(q);
    this->playerCardsDrawn++;
    Card temp = deck.drawCard();
    p = &temp;
    cout << "1. kort dealer: " << p->toString() << endl;
    this->dealerHand = getDealerCardValue(p, dealerHand);
    this->dealerCardsDrawn++;
    temp = deck.drawCard();
    p = &temp;
    this->dealerHand += getDealerCardValue(p, dealerHand);
    this->dealerCardsDrawn++;
}

void BlackJack::playGame() {
    BlackJack game;
    game.drawInitialCards();
    if(game.playerHand < 21 && game.dealerHand < 21) {
      bool check = true;
      while(check) {
        check = askPlayerDrawCard();
        if(check) {
          Card *p;
          Card temp = deck.drawCard();
          p = &temp;
          cout << "Kort: " << p->toString() << endl;
          game.playerHand += getPlayerCardValue(p);
          game.playerCardsDrawn++;
          if(dealerHand < 17) {
            temp = deck.drawCard();
            p = &temp;
            game.dealerHand += getDealerCardValue(p, dealerHand);
            game.dealerCardsDrawn++;
          }
          if(game.playerHand >= 21 || game.dealerHand >= 21) {
              check = false;
          }
        }
    }
        while(game.dealerHand < 17) {
            Card *p;
            Card temp = deck.drawCard();
            p = &temp;
            game.dealerHand += getDealerCardValue(p, dealerHand);
            game.dealerCardsDrawn++;
        }

        cout << game.playerHand << " " << game.dealerHand << endl;

        if(game.playerHand > 21 && game.dealerHand > 21) {
            cout << "Uavgjort" << endl;
        }
        else if(game.dealerHand > 21) {
            cout << "Winner, winner, chicken dinner" << endl;
        }
        else if(game.playerHand > 21) {
            cout << "Bust" << endl;
        }
        else if(game.dealerHand == 21) {
            cout << "Dealer har blackjack" << endl;
        }
        else if(game.dealerHand >= game.playerHand) {
            cout << "Tapt" << endl;
        }
        else if(game.playerHand == 21) {
            cout << "Blackjack!" << endl;
        }
        else {
            cout << "Mulig du vant!" << endl;
        }
    }
}

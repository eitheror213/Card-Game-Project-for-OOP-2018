// HW5 C331 SP18

#include "carddeck.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <memory>

static int const SUIT_NUM = 4;
static int const FACE_NUM = 13;

CardDeck::CardDeck(){
    restoreDeck();
}

CardHand CardDeck::deal(int handSize){
    srand(time(0));

    std::shared_ptr<CardHand> hand(new CardHand);
    int randInt;

    if(handSize > this->count()) {
        restoreDeck();
    }

    for(int i = 0; i < handSize; i++) {
        randInt = rand() % this->count();
        hand->append((*this)[randInt]);
        this->removeAt(randInt);
    }
    return *hand;
}

QString CardDeck::toString() {
    QString str;
    for(Card& card : *this) {
        str.append(card.toString() + ", ");
    }
    return str;
}

void CardDeck::restoreDeck() {
    if(!this->isEmpty()) {
        this->clear();
    }
    for(int suit = 0; suit < SUIT_NUM; suit++) {
        for(int face = 0; face < FACE_NUM; face++) {
            std::shared_ptr<Card> card(new Card(face, suit));
            this->append(*card);
        }
    }
}

int CardDeck::getCardsLeft() const { return this->count(); }

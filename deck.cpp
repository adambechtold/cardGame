//
// Created by Patrick on 2/6/17.
//

#include "deck.h"
#include "Card.h"

Deck::Deck() {
        this->suits = ("Club", "Diamonds", "Hearts", "Spades");
        // loop through an assign values
    }

void Deck::shuffle() {
    //shuffle some shit
}
ostream &operator<<(ostream &ostr, const Deck &d) {
    return <#initializer#>;
}
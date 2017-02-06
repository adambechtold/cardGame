//
// Created by Patrick on 2/6/17.
//

#include <iostream>

#ifndef DECK_H
#define DECK_H

class Deck {
private:
    node<Card> *front;

    string suits[4];

public:

    Deck();

    void shuffle();
};

#endif //PROJECT2_DECK_H

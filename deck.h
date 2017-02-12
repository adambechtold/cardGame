//
// Created by Adam Bechtold and Patrick Buzza on 2/6/17.
//

#ifndef DECK_H
#define DECK_H
using namespace std;
#include <iostream>
#include <string>
#include "Card.h"
#include "d_node.h"
class Deck
{
public:
    void shuffle(); //shuffles entire deck
    Deck();

private:
    node<Card> *front; //pointer to the front of the deck
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    int size;
    friend ostream& operator<< (ostream& ostr, const Deck& d);
};

#endif //PROJECT2_DECK_H

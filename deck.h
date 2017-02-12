// Project 2a
// Adam Bechtold & Patrick Buzza
//
// Header file for the Deck class
// This class represents a deck of cards in the form of a linked list. A Deck
// object has a pointer to the front of the linked list, a list of suits in the
// deck, and a integer for the size of the deck.
// Also includes declarations of the methods necessary to use a Deck in a
// card game including:
//   - a Constructor
//   - shuffle
//   - overloaded << operator

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
    Deck();
    void shuffle(); //shuffles entire deck
    friend ostream& operator<< (ostream& ostr, const Deck& d);

private:
    node<Card> *front; //pointer to the front of the deck
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    int size;
};

#endif //PROJECT2_DECK_H

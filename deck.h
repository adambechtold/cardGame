//
// Created by Patrick on 2/6/17.
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
    friend ostream& operator<< (ostream& ostr, const Deck& d);
    void shuffle();
    Deck();

private:
    //node<Card> *p1;
    node<Card> *front;
    string suits[4];
    int size;

};

#endif //PROJECT2_DECK_H

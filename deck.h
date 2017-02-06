//
// Created by Patrick on 2/6/17.
//

#ifndef DECK_H
#define DECK_H
using namespace std;
#include <iostream>
#include <string>
class Deck
{
public:
    friend ostream& operator<< (ostream& ostr, const Deck& d);
    void shuffle();
    Deck();

private:
    node<Card> *front;
    string suits[4];

};

#endif //PROJECT2_DECK_H

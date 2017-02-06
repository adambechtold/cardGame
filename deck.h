//
// Created by Patrick on 2/6/17.
//

#ifndef DECK_H
#define DECK_H
using namespace std;
#include <iostream>
#include <string>
#include <ostream>
class Deck
{
public:
    friend ostream& operator<< (ostream& ostr, const Deck& d);

private:
    Deck();
    ShuffleDeck();

};

#endif //PROJECT2_DECK_H

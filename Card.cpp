//
// Created by Adam Bechtold on 2/5/17.
//

#include "Card.h"
#include <iostream>

Card::Card(int value, string suit)
// constructor for a card
{
    this->value = value;
    this->suit = suit;
}

void Card::setValue(int value)
// set the value of a playing card
{
    this->value = value;
}

void Card::setSuit(string suit)
// set the suit of the playing card
{
    this->suit = suit;
}

int Card::getValue() const
// get the value of this playing card
{
    return this->value;
}

string Card::getSuit() const
// return the suit of this playing card
{
    return this->suit;
}

ostream& operator<< (ostream& ostr, const Card& c)
// overload << operator to print fields of the card
{
    int i = c.value;

    switch (i) {
        case 1: //ace
            ostr << "Ace of " << c.getSuit();
            return ostr;
        case 11:
            ostr << "Jack of " << c.getSuit();
            return ostr;
        case 12:
            ostr << "Jack of " << c.getSuit();
            return ostr;
        case 13:
            ostr << "Jack of " << c.getSuit();
            return ostr;
        default:
            ostr << c.getValue() << " of " << c.getSuit();
            return ostr;
    }
}
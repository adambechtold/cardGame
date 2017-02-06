//
// Created by Adam Bechtold on 2/5/17.
//

#include "Card.h"
#include <iostream>

Card::Card(int value, string suite)
// constructor for a card
{
    this->value = value;
    this->suite = suite;
}

void Card::setValue(int value)
// set the value of a playing card
{
    this->value = value;
}

void Card::setSuite(string suite)
// set the suite of the playing card
{
    this->suite = suite;
}

int Card::getValue() const
// get the value of this playing card
{
    return this->value;
}

string Card::getSuite() const
// return the suite of this playing card
{
    return this->suite;
}

ostream& operator<< (ostream& ostr, const Card& c)
// overload << operator to print fields of the card
{
    ostr << " " << c.getValue() << " of " << c.getSuite();
    return ostr;
}
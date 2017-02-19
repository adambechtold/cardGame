// Project 2a
// Adam Bechtold & Patrick Buzza
//
// cpp file for the Card class
// Implements the functions declared in the Card header file including:
//   - a Constructor
//   - setValue
//   - setSuit
//   - getValue
//   - getSuit

#include "Card.h"

Card::Card(int value, string suit)
// constructor for a card
{
    this->value = value;
    this->suit = suit;
}

Card::Card(const Card& rhs)
//copy constructor for a new card based on existing card
{
    *this = rhs;
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

void Card::count(int &score)
{
    int cardvalue = this->getValue();
    string cardsuit = this->getSuit();
    if (cardvalue == 1)
        score = score + 10;
    else if (cardvalue > 10 && cardvalue < 14)
        score = score + 5;
    else if (cardvalue == 7)
        score = score/2;
    else if (cardvalue > 1 && cardvalue < 7)
        score = 0;
    if (cardsuit == 'Heart')
        score++;
}


ostream& operator<< (ostream& ostr, const Card& c)
// overload << operator to print fields of the card
{
    int i = c.value;

    //converts number in card to normal card naming conventions
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

Card Card::operator= (const Card &deckcard)
// overload assignment operator for
{
    this->setValue(deckcard.getValue());
    this->setSuit(deckcard.getSuit());
    return *this;
}

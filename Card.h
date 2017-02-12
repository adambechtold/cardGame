// Project 2a
// Adam Bechtold & Patrick Buzza
//
// Header file for the Card class
// Contains the private fields that hold the playing card's value and suit.
// Also includes declarations of the methods necessary to use the Cards in a
// card game including:
//   - a Constructor
//   - setValue
//   - setSuit
//   - getValue
//   - getSuit


#include <iostream>
#include <string>

using namespace std;

#ifndef PROJECT2_CARD_H
#define PROJECT2_CARD_H

// to represent playing cards
class Card {
public:
    Card(int value, string suit); //constructor for Card class

    void setValue(int value);  //sets the value of a card

    void setSuit(string suit); //sets the suit of a card

    int getValue() const; //returns the value of a card

    string getSuit()const; //returns the suit of a card


private:
    int value;
    string suit;
    friend ostream& operator<< (ostream& ostr, const Card& c);
};


#endif //PROJECT2_CARD_H

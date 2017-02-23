// Project 2a
// Adam Bechtold & Patrick Buzza
//
// Header file for the Card class
// Contains the private fields that hold the playing card's value and suit.
// Also includes declarations of the methods necessary to use a Deck in a
// card game including:
//   - a Constructor
//   - setValue
//   - setSuit
//   - getValue
//   - getSuit
//   - overloaded << operator


#include <iostream>
#include <string>

using namespace std;

#ifndef PROJECT2_CARD_H
#define PROJECT2_CARD_H

// to represent playing cards
class Card {
public:
    Card(int value, string suit); //constructor for Card class

    Card(const Card& rhs); //copy constructor for Card class

    void setValue(int value);  //sets the value of a card

    void setSuit(string suit); //sets the suit of a card

    int getValue() const; //returns the value of a card

    string getSuit()const; //returns the suit of a card

    //Card operator= (const Card &deckcard);
    //assignment overload to be used in copy constructor for new card objects

    void count(int &score);

private:
    int value;
    string suit;
    friend ostream& operator<< (ostream& ostr, const Card& c);
    // operator overload for << to print the cards of the deck
};


#endif //PROJECT2_CARD_H

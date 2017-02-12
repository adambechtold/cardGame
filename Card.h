//
// Created by Adam Bechtold and Patrick Buzza on 2/5/17.
//

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

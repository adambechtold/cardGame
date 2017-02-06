//
// Created by Adam Bechtold on 2/5/17.
//

#include <string>

using namespace std;

#ifndef PROJECT2_CARD_H
#define PROJECT2_CARD_H

// to represent playing cards
class Card {
public:
    int value;
    string suit;

    Card(int value, string suit);

    void setValue(int value);

    void setSuit(string suit);

    int getValue() const;

    string getSuit()const;

    friend ostream& operator<< (ostream& ostr, const Card& c);
};


#endif //PROJECT2_CARD_H

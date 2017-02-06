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
    string suite;

    Card(int value, string suite);

    void setValue(int value);

    void setSuite(string suite);

    int getValue() const;

    string getSuite()const;

    friend ostream& operator<< (ostream& ostr, const Card& c);
};


#endif //PROJECT2_CARD_H

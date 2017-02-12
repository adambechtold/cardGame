//
// Created by Adam Bechtold and Patrick Buzza on 2/6/17.
//


#include <iostream>

#include "Card.h"
#include "deck.h"


using namespace std;

int main() {


    //Initializes our 52 card deck and number of shuffles
    Deck d = Deck();
    int numshuffles = 13;

    //Prints out the deck in order
    cout << d;

    cout << "----shuffle time------" << endl;

    //shuffles the deck a predefined number of times
    for (int i = 0; i < numshuffles; i++)
        d.shuffle();

    cout << endl << d; //prints out the shuffled deck
    cout << "complete";

    return 0;
}
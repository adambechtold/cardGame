//
// Created by Adam Bechtold and Patrick Buzza on 2/6/17.
//
//  Main file for Project Two: Flip
//  This file initializes the deck
//  It also prints out the deck, both in order and after being shuffled n times
//


#include <iostream>

#include "Card.h"
#include "deck.h"


using namespace std;

int main() {


    //Initializes our 52 card deck and number of shuffles desired
    Deck d = Deck();
    int numshuffles = 3;

    //Prints out the deck in order
    cout << d;

    //shuffles the deck a predefined number of times
    for (int i = 0; i < numshuffles; i++)
        d.shuffle();

    //prints out the shuffled deck
    cout << "Shuffled deck:" << endl << d;
    cout << "complete";

    return 0;
}
// Project 2a
// Adam Bechtold & Patrick Buzza
//
//  Main file for Project Two: Flip
//  This file initializes the deck
//  It also prints out the deck, both in order and after being shuffled n times

#include <iostream>

#include "Card.h"
#include "deck.h"


using namespace std;

void playFlip()
{
    //Initializes our 52 card deck and number of shuffles desired
    Deck d = Deck();
    int i, counter, score = 0;
    int numshuffles = 3;
    string name;
    bool stop = 0;
    char decision = 'N';

    //shuffles the deck a predefined number of times
    for (i; i < numshuffles; i++)
        d.shuffle();

    cout << "Hello there! Welcome to Flip, where honor can be won and lost";
    cout << " on a flip of a card. To get started, please tell us your name:" << endl;
    cin >> name;
    cout << "Alright, " << name << ", there are a few rules for this game." << endl;
    cout << "1) The deck shall be shuffled three times" << endl;
    cout << "2) The top 24 cards shall be drawn from the deck." << endl;
    cout << "3) You will flip each card over one by one, and are";
    cout << "allowed to stop at any point." << endl << endl;
    cout << "Each card is assigned a value, as shown below." << endl;
    cout << "Ace: +10 points. \n" << "Face card (Jack, Queen, King): +5 points. \n";
    cout << "8, 9, or 10: +0 points. \n" << "7: Lose half your points. \n";
    cout << "2, 3, 4, 5, or 6: Lose all your points. \n";
    cout << "Additionally, if the card you drew was a heart,"
            "you receive a single point. \n";
    cout << "You are now ready to play! Time to draw the first card. \n";

    //TODO We still need to debug this.  My idea hear was to draw 24 cards at once, and put them in a new list.  As we read them out to the player, we then call the replace function, putting them back in the deck. However, I now realizing that instantiating an empty class array with 24 items might not be the best way to go about this.  A dynamic link list would probably hand this better, but I didn't really want to dive into that at the moment (It's very possible by the time you look at this, I'll have tackled this, but I want to leave this comment here until we talk about this, because I think this is an important aspect we should discuss).
    /*
    //builds a 24 card hand for the player to play from
    for (i; i<24; i++)
    {
        hand[i]=d.deal();
        //cout << hand[i] << newl;
    }
    do
    {
        cout << "You drew the " << hand[counter].getValue() << " of " << hand[counter].getSuit();
        hand[counter].count(score);
        cout << "Your score is now" << score;
        cout << "Would you like to draw another card? (Y/N) \n";
        cin >> decision;
        if (decision == 'Y')
            stop = 1;
        counter++;
    }
    while (!stop && counter<24);
    */
}

int main() {
    playFlip();
    return 0;
}
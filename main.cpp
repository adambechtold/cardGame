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
    //Initializes the framework of our game, including the 52-card deck,
    //counters, error checking variables, the score, and the player's name
    Deck d = Deck();
    Deck hand = Deck(24);
    bool chosen[24] = {false};
    bool stop = {false};
    int counter, score, card = 0;
    int numshuffles = 3;
    string name;
    char decision = 'N';

    //shuffles the deck a predefined number of times
    for (int i=0; i < numshuffles; i++)
        d.shuffle();
    //interface statements; introducing the game and rules
    cout << "Hello there! Welcome to Flip, where honor can be won and lost on";
    cout << " a flip of a card. To get started, please tell us your name: \n";
    cin >> name;
    cout << "Alright, " << name << ", there are a few rules for this game.\n";
    cout << "1) The deck shall be shuffled three times" << endl;
    cout << "2) The top 24 cards shall be drawn from the deck." << endl;
    cout << "3) You will choose a card to flip, one by one, and are ";
    cout << "allowed to stop at any point." << endl << endl;
    cout << "Each card is assigned a value, as shown below." << endl;
    cout << "Ace: +10 points. \n";
    cout << "Face card (Jack, Queen, King): +5 points. \n";
    cout << "8, 9, or 10: +0 points. \n" << "7: Lose half your points. \n";
    cout << "2, 3, 4, 5, or 6: Lose all your points. \n";
    cout << "Additionally, if the card you drew was a Heart,"
            "you receive a single point. \n";
    cout << "You are now ready to play! Time to draw the first card. \n";

    //builds a 24 card hand for the player to choose from
    for (int j=0; j<24; j++)
    {
        hand.replace(d.deal());
    }
    do
    {
        //prompt user to choose their card
        cout << "Please choose your card: \n";
        cin >> card;

        //bonus section: determine if card has already been selected
        while (chosen[card])
        {
            cout << "You've already chosen this card,";
            cout << " please pick a different card.\n";
            cin >> card;
        }
        chosen[card]={true};
        Card Chosencard = hand.depth(card);
        cout << "You drew the " << Chosencard.getValue();
        cout << " of " << Chosencard.getSuit();
        Chosencard.count(score);
        cout << "Your score is now" << score;
        cout << "\nWould you like to draw another card? (Y/N) \n";
        cin >> decision;
        if (decision == 'Y')
            stop = 1;
        counter++;
    }
    while (!stop && counter<24);
    cout << "Wasn't that fun? Lets see how well you did! \n";
    cout << "Score: " << score;
    cout << "\n.\n..\n...\n....\n.....\n...Not bad.";
}

int main()
{
    playFlip();
    return 0;
}
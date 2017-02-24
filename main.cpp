// Project 2b
// Adam Bechtold & Patrick Buzza
//
//  Main file for Project Two: Flip
//  the main function is simply responsible for calling the function playFlip
//  playFlip controls the playing of our game, including initializing multiple
//  deck object,

#include <iostream>

#include "Card.h"
#include "deck.h"


using namespace std;

void playFlip()
{
    //Initializes the framework of our game, including the 52-card deck,
    //counters, error checking variables, the score, and the player's name
    Deck d = Deck();
    Deck drawn = Deck(24);
    Deck hand = Deck(1);
    bool chosen[24] = {false};
    bool stop = false;
    int counter, score, cardindex, cind = 0;
    int numshuffles = 3;
    string name;
    char decision = 'N';

    cout << "Original deck:\n\n" << d << endl;
    cout << "---------------" << endl;

    //shuffles the deck a predefined number of times
    for (int i = 0; i < numshuffles; i++)
        d.shuffle();

    cout << "Shuffled deck:\n" << d << endl;

    //interface statements; introducing the game and rules
    cout << "Hello there! Welcome to Flip, where honor can be won and lost on";
    cout << " a flip of a card. To get started, please tell us your name: ";
    cin >> name;
    cout << "Oh great, " << name << " again .... There are rules you'll ";
    cout << "have to follow to play this game.  They are as follows \n";
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
            " you receive a single point. \n";
    cout << "You are now ready to play! Time to draw the first card. \n";

    //builds a 24 card hand for the player to choose from
    for (int j = 0; j < 24; j++)
    {
        drawn.replace(d.deal());
    }

    cout << "Your hand:\n" << drawn;
    cout << "----------" << endl;
    cout << "Remaining cards in the deck:\n" << d << endl;

    do
    {
        //prompt user to choose their card
        cardindex = -1;
        while(cardindex <= 0 || 25 <= cardindex) {
            cout << "Please choose which card you'd like to draw (1-24): ";
            cin >> cind;
            cardindex = cind;
        }

        cardindex--;

        //bonus section: determine if card has already been selected
        while (chosen[cardindex])
        {
            cout << "You've already chosen this card,";
            cout << " please pick a different card: ";
            cin >> cind;
            cardindex = cind - 1;
        }

        //condition to prevent same card from being selected twice
        chosen[cardindex] = {true};
        Card Chosencard = drawn.depth(cardindex); //draws chosen card
        hand.replace(Chosencard); //adds it to the current hand
        cout << "You drew the " << Chosencard << endl;
        Chosencard.count(score); //calculates score
        cout << "Your current hand includes: \n" << hand;
        cout << "-------" << endl;

        //checks if all cards in the hand have already been drawn
        if (counter == 23)
        {
            cout << "You can no longer draw, as you've selected all ";
            cout << "the cards in your hand. \n";
            break;
        }
        else
        {
            cout << "Your score is now: " << score;
            cout << "\nWould you like to draw another card? (Y/N): ";
            cin >> decision;
            if (decision == 'N' || decision == 'n')
                stop = 1;
            counter++;
        }

    } //do-while loop to allow the player to draw multiple cards
    while (!stop && counter<24);
    cout << "Wasn't that fun? Lets see how well you did! \n";
    cout << "Score: " << score;
    cout << "\n...\n...\n...\n...\n...\nNot bad.";
} //end of playFlip function

int main()
{
    playFlip();
    return 0;
}
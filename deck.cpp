// Project 2a
// Adam Bechtold & Patrick Buzza
//
// cpp file for the Deck class
// Implements the functions declared in the Deck header file including:
//   - a Constructor
//   - shuffle
//   - overloaded << operator

#include "d_node.h"
#include "deck.h"
#include "d_random.h"


Deck::Deck()
//constructor for a deck of cards
{
    //initializes length of deck and front of deck pointer
    this->size = 52;
    this->front = NULL;

    //Adds cards to the deck backwards, such that the Ace will be on top
    for(int i = 3; i >= 0; i--) {
        for(int j = 12; j >= 0; j--) {
            this->front = new node<Card> (Card(j+1, this->suits[i]), this->front);
        }
    }
}

void Deck::shuffle()
//shuffle shuffle the deck using a Fisher-Yates algorithm. For more info
//  on the Fisher-Yates process: http://bit.ly/2lBETDk
{
    //initializes the size of the deck to be shuffled
    int size = this->size;
    int sCount = 0;

    //creates pointers to access the entire deck of cards
    node<Card> *rollingFront = this->front;
    node<Card> *targetNode = this->front;

    //create random number generator - d_random.h currently requires positive
    //   seed
    randomNumber randGen = randomNumber(10);

    //move through the deck swapping a selected element with another deeper
    // in the list
    while(size > 1) {
        // select a depth for the target
        long i = randGen.random(size); //select depth of target node

        //if depth is zero, element at this node stays the same
        if(i == 0) {
            rollingFront = rollingFront->next;
            targetNode = rollingFront;
            size--;
            sCount++;
            continue;
        }

        // else move into array
        long depth = i;
        while(i > 0){
            targetNode = targetNode->next;
            i--;
        }

        // swap cards
        Card temp = targetNode->nodeValue;
        targetNode->nodeValue = rollingFront->nodeValue;
        rollingFront->nodeValue = temp;

        //advance pointers
        rollingFront = rollingFront->next;
        targetNode = rollingFront;
        size--;
        sCount++;
    }
}

// operator overload for << to print the cards of the deck›
ostream &operator<<(ostream &ostr, const Deck &d)
{
    node<Card> *curr;
    curr = d.front;
    while (curr != NULL)
    {
        cout << curr->nodeValue << endl;
        curr = curr->next;
    }
}
//
// Created by Patrick on 2/6/17.
//

#include "d_node.h"
#include "deck.h"
#include "d_random.h"


Deck::Deck()
//constructor for a deck of cards
{
    this->size = 52;
    this->suits;
    string suitsOne[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    this->front = NULL;

    for(int i = 3; i >= 0; i--) {
        for(int j = 12; j >= 0; j--) {
            this->front = new node<Card> (Card(j+1, suitsOne[i]), this->front);
        }
    }
}

void Deck::shuffle()
//shuffle that shit Fisher-Yates style
{
    int size = this->size;
    int sCount = 0;

    node<Card> *rollingFront = this->front;
    node<Card> *targetNode = this->front;

    randomNumber randGen = randomNumber(11);

    while(size > 1) {

        //move to the target node
        //ensure that the preTarget pointer is staying one spot behind target
        long i = randGen.random(size); //select depth of target node

        //if depth is zero, element at this node stays the same
        if(i == 0) {
           // cout << "just advance" << endl;
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

        cout << "s: " << size << " d: " << depth;
        cout << " : switching " << rollingFront->nodeValue << " w/ ";
        cout << targetNode->nodeValue << endl;

        cout << *this;

        cout << endl;

        Card temp = targetNode->nodeValue;
        targetNode->nodeValue = rollingFront->nodeValue;
        rollingFront->nodeValue = temp;

        //advance pointers
        rollingFront = rollingFront->next;
        targetNode = rollingFront;
        size--;
        sCount++;
    }

    cout << endl << "sCout: " << sCount << endl;
}

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
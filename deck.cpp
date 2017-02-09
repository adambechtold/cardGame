//
// Created by Patrick on 2/6/17.
//

#include "d_node.h"
#include "deck.h"
#include "Card.h"


Deck::Deck()
//constructor for a deck of cards
{
    this->size = 6;
    this->suits;
    string suitsOne[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    this->front = NULL;

    for(int i = 1; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {
            this->front = new node<Card> (Card(j+1, suitsOne[i]), this->front);
        }
    }
}

void Deck::shuffle()
//shuffle that shit
{
    int size = this->size;

    node<Card> *preFront = this->front;
    node<Card> *frontSwap = this->front;  //
    node<Card> *preTarget = this->front;  //points to target (i.e. item in list to be swapped)
    node<Card> *targetSwap = this->front; //location of target node

    while(size > 1) {

        //move to the target node
        //ensure that the preTarget pointer is staying one spot behind target
        int i = rand() % size; //select depth of target node

        //if depth is zero, element at this node stays the same
        if(i == 0) {
            preFront = preFront->next;
            frontSwap = frontSwap->next;
            preTarget = preTarget->next;
            targetSwap = targetSwap->next;
            size--;
            continue;
        }

        // else move into array
        int depth = i;
        while(i > 0){
            targetSwap = targetSwap->next;
            if (size < this->size) {
                preTarget = preTarget->next;
            }

            i--;
        }

        //treat first element differently to avoid losing the front of this list
        if (frontSwap == this->front && targetSwap == frontSwap->next) {
            //swap em
            this->front = targetSwap;
            frontSwap->next = targetSwap->next;
            targetSwap->next = frontSwap;
        }
        else if (frontSwap == this->front && targetSwap != frontSwap->next) {
            //swap pointers around
            this->front = targetSwap;
            node<Card> *temp = targetSwap->next;
            targetSwap->next = frontSwap->next;

            preTarget->next = frontSwap;
            frontSwap->next = temp;

            delete temp; //TODO not sure if this is necessary
        }
        else if (preTarget == frontSwap) {
            //swap pointers around
            frontSwap->next = targetSwap->next;
            targetSwap->next = frontSwap;
            preFront->next = targetSwap;
        }
        else { //(preTarget != frontSwap)
            //swap em
            preTarget->next = frontSwap;
            preFront->next = targetSwap;
            node<Card> *temp = targetSwap->next;
            targetSwap->next = frontSwap->next;
            frontSwap->next = temp;

            delete temp; //TODO not sure if this is necessary see above
        }

        //reset pointers and advance
        preFront = targetSwap;
        preTarget = targetSwap;
        targetSwap = targetSwap->next;
        frontSwap = targetSwap;

        //decrease size by one
        size--;
    }
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
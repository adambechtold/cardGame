//
// Created by Patrick on 2/6/17.
//

#include "d_node.h"
#include "deck.h"
#include "Card.h"


Deck::Deck()
//constructor for a deck of cards
{
    this->size = 52;
    this->suits;
    string suitsOne[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    this->front = NULL;

    for(int i = 3; i >= 0; i--) {
        for(int j = 13; j >= 0; j--) {
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

    while(size > 0) {

        //move to the target node
        //ensure that the preTarget pointer is staying one spot behind target
        int i = rand() % size; //select depth of target node

        //if depth is zero, element at this node stays the same
        if(i == 0) {
            size--;
            preFront = preFront->next;
            frontSwap = frontSwap->next;
            preTarget = preTarget->next;
            targetSwap = targetSwap->next;
            continue;
        }

        // else move into array
        int depth = i;
        while(i > 0){
            targetSwap = targetSwap->next;
            if (i != depth)
                preTarget = preTarget->next;
            i--;
        }

        //treat first element differently to avoid losing the front of this list
        if (frontSwap == this->front) {
            //swap pointers around
            this->front = targetSwap;
            node<Card> *temp = targetSwap->next;
            targetSwap->next = this->front->next;

            preTarget->next = frontSwap;
            frontSwap->next = temp;

            delete temp; //TODO not sure if this is necessary

            //reset pointers and advance
            frontSwap = this->front->next;
            preTarget = this->front;
            targetSwap = this->front->next;
            //preFront is set to front
        }
        else {

        }


        //swap Node1->next and Node2->next


        //place current node at the front of the linked list
//        tempFront
//
//        node<Card> *temp = this->front;
//        temp->next = front->next;
//
//        frontTemp->next =

        Card temp = curr->nodeValue;
        front->nodeValue = curr->nodeValue;
        curr->nodeValue = temp;

        tempFront = tempFront->next;
        curr = tempFront;

        size--;
    }

    //delete tempFront;
    //delete curr;
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
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
    node<Card> *tempFront = this->front;
    node<Card> *curr = front;
    int size = this->size;

    while(size > 0) {

        //move the current node object a random amount deep
        int i = rand() % size;
        while(i > 0){
            curr = curr->next;
            i--;
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
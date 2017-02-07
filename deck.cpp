//
// Created by Patrick on 2/6/17.
//

#include "d_node.h"
#include "deck.h"
#include "Card.h"

Deck::Deck() {
    this->size = 52;
    this->suits;
    string suitsOne[] = {"Club", "Diamonds", "Hearts", "Spades"};


    node<Card> *curr = new node<Card>(Card(1, suitsOne[0]));
    this->front = curr;

    node<Card> *t;
    // loop through an assign values
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            t = curr;
            curr = new node<Card>(Card(j, suitsOne[i]));
            t->next = curr;
        }
    }

    cout << "deck complete";
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
//
// Created by Patrick on 2/6/17.
//

#include "deck.h"
#include "Card.h"

Deck::Deck() {
    this->suits = ("Club", "Diamonds", "Hearts", "Spades");
    this->size = 52;

    node<Card> *curr = this->front;

    // loop through an assign values
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            curr->nodeValue = Card(i, suits[j]);
            node *temp;
            curr->next = temp;
            delete temp;
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

        //move

        node<Card> *temp = this->front;
        temp->next = front->next;

        frontTemp->next =

        Card *temp = curr->nodeValue;
        front->nodeValue = curr->nodeValue;
        curr->nodeValue = temp;

        frontTemp = frontTemp->next;
        curr = frontTemp;

        size--;
    }

    delete tempFront;
    delete curr;
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
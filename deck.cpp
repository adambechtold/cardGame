//
// Created by Patrick on 2/6/17.
//

#include "deck.h"
#include "Card.h"

using namespace std;

Deck::Deck() {
    this->suits = ("Club", "Diamonds", "Hearts", "Spades");
    this->size = 52;
    // loop through an assign values
}

void Deck::shuffle()
//shuffle that shit
{
    node<Card> *front = this->front;
    node<Card> *curr = front;
    int size = this->size;

    while(size > 0) {
        int i = rand() % size;

        while(i > 0){
            curr = curr->next;
            i--;
        }

        Card temp = curr->nodeValue;
        front->nodeValue = curr->nodeValue;
        curr->nodeValue = temp;

        front = front->next;
        curr = front;

        size--;
    }

    delete front;
    delete curr;
}

ostream &operator<<(ostream &ostr, const Deck &d) {
    return <#initializer#>;
}
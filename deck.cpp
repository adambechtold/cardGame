//
// Created by Patrick on 2/6/17.
//

#include "deck.h"
#include "Card.h"

Deck::Deck() {
    this->suits = ("Club", "Diamonds", "Hearts", "Spades");
    this->size = 52;
    front = NULL;
    // loop through an assign values
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Card temp = Card(j, suits[i]);

            p1 = new node <Card> (j, suits);
            if (i == 0 && j == 0)
                front = p1;
            p1=p1->next;
        }
    }
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
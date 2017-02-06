//
// Created by Patrick on 2/6/17.
//

#include "deck.h"
#include "Card.h"

Deck::Deck() {
        this->suits = ("Club", "Diamonds", "Hearts", "Spades");
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
{
    //shuffle some shit

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
// Project 2a
// Adam Bechtold & Patrick Buzza
//
// cpp file for the Deck class
// Implements the functions declared in the Deck header file including:
//   - a Constructor
//   - an overloaded Constructor
//   - a Destructor
//   - deal
//   - replace
//   - shuffle
//   - depth
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

Deck::Deck(int size)
//overloaded constructor for a deck of cards, used to store hand of card
{
    //initializes length of deck and front of deck pointer
    this->size = 0;
    this->front = NULL;
}

Deck::~Deck()
//destructor for a deck of cards
{
    node <Card> *ptr; //initializes pointer
    //loops until every card in the deck is removed
    while(this->front != NULL)
    {
        ptr = this->front; //assigns pointer to point to the front of the deck
        this->front = this->front->next; //increments the front of the deck
        delete(ptr);                     //deletes previous front value
        this->size--;                    //decrements the size
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

Card Deck::deal()
// deal returns the top card of the deck, and removes it from the deck
{
    node <Card> *ptr = this->front;
    Card value = this->front->nodeValue;
    this->front = this->front->next;
    delete (ptr);
    this->size--;
    return value;
}

void Deck::replace(Card c)
//place the given card at the bottom of this deck
{
    node<Card> *curr = this->front;
    node<Card> *last =  new node<Card>(c);
    //creates a pointer to the front of the deck
    if (this->front == NULL)
    {
        this->front = last;
        //this->front->nodeValue = c;
        this->size++;
    }
    else
    {
        //loops until curr points to the last object in the linked list
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        //points to value passed to the function, then inserts value at end of list
        curr->next = last;
        //curr->next->nodeValue = c;
        //increments the size variable of the deck
        this->size++;
    }
}

Card Deck::depth(int depth)
//moves through the deck class and returns the object at requested depth
{
    node<Card> *ptr = this->front; //pointer to the front of the deck

    //loops until the pointer reaches the desired index
    for (int j = 0; j < depth; j++)
    {
        ptr = ptr->next;
    }
    return ptr->nodeValue; //returns the value at desired depth
}

ostream &operator<<(ostream &ostr, const Deck &d)
// operator overload for << to print the cards of the deck›
{
    node<Card> *curr = d.front; //creates a pointer to the front of the deck
    //while loop moves through the entire linked list to print out deck
    while (curr != NULL)
    {
        cout << curr->nodeValue << endl;
        curr = curr->next;
    }
    return ostr;
}
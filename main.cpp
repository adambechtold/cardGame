#include <iostream>

#include "Card.h"
#include "deck.h"


using namespace std;

int main() {

    Card c = Card(3, "Hearts");

    Deck d = Deck();

    cout << c;

    cout << d;

    cout << "----shuffle time------" << endl;
    d.shuffle();

    cout << endl << d;

    cout << "complete";

    return 0;
}
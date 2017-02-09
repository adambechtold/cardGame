#include <iostream>

#include "Card.h"
#include "deck.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Card c = Card(3, "Hearts");

    Deck d = Deck();

   // cout << c;

    cout << d;

    cout << "----shuffle time------" << endl;
    d.shuffle();

    cout << d;

    return 0;
}
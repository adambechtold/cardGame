#include <iostream>

#include "Card.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Card c = Card(3, "Hearts");

    cout << c;

    return 0;
}
#pragma once

#include <string>

enum Suit {
    DIAMONDS, HEARTS, SPADES, CLUBS
};

class Card {
private:
    Suit m_suit;
    int m_value; // could be an enum but I dont care
public:
    Card(int value, Suit suit);

    // you need to delete the pointer you get once you are done with it!
    std::string* name();

    int value();
};


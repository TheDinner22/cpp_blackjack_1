#pragma once

#include <string>

enum Suit {
    DIAMONDS, HEARTS, SPADES, CLUBS
};

class Card {
private:
    Suit m_suit;
    int m_value; // could be an enum but I dont care
    std::string m_name;
public:
    // ace of diamonds by default
    Card();
    Card(int value, Suit suit);

    const std::string& name() const;

    int value() const;
};

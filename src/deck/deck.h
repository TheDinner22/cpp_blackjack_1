#pragma once

#include <set>
#include <string>
#include <vector>

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

class Deck {
private:
    std::vector<Card> m_deck;
    std::set<int> m_used_cards;

private:
    std::vector<Card> generate_cards();

    int generate_random_number();

public:
    Deck(){
        m_deck = generate_cards();
        
        // Providing a seed value
        srand((unsigned) time(NULL));
    }

    void reset();

    const Card& draw_card();

    // for debugging
    void print() const;
};


#pragma once

#include <array>
#include <string>

enum Suit {
    DIAMONDS, HEARTS, SPADES, CLUBS
};

class Card {
private:
    Suit m_suit;
    int m_value; // could be an enum but I dont care
public:
    // ace of diamonds by default
    Card();
    Card(int value, Suit suit);

    // you need to delete the pointer you get once you are done with it!
    std::string* name();

    int value();
};

class Player {
private:
    std::string* m_name; // kill when done
    Card* m_card_v; // kill when done
    int m_card_c;
    int m_money;
public:
    Player(std::string* name) : m_name(name), m_card_v(nullptr), m_card_c(0), m_money(100) { }

    ~Player(){
        delete m_name;
        delete [] m_card_v;
    }

    int card_total() const; 

    void reset_hand();

    // this class will handle the card
    void add_card(const Card& new_card);
};

std::array<Card, 52>* make_unshuffled_deck();


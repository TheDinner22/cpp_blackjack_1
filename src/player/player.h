#pragma once

#include <array>
#include <string>
#include "../deck/deck.h"

class Player {
private:
    std::string m_name;
    Card* m_card_v; // kill when done
    int m_card_c;
    int m_money;
public:
    Player(std::string name) : m_name(name), m_card_v(nullptr), m_card_c(0), m_money(100) { }

    ~Player(){
        delete [] m_card_v;
    }

    int card_total() const; 

    const std::string& name() const;

    void reset_hand();

    void print_hand() const;

    // this class will handle the card
    void add_card(const Card& new_card);
};


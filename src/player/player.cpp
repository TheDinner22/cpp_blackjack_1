#include <algorithm>
#include <array>
#include <exception>
#include <string>
#include <iostream>
#include "player.h"


int Player::card_total() const {
    int total = 0;
    for (int i = 0; i < m_card_c; i++) {
        total += std::min( (m_card_v + i)->value(), 10 );
    }
    return total;
}

void Player::print_hand() const {
    if (m_card_c == 0){
        std::cout << "no cards in hand!" << std::endl;
        return;
    }

    for (int i = 0; i < m_card_c; i++) {
        const std::string& card_name = (m_card_v + i)->name();
        std::cout << card_name << std::endl;
    }
}

const std::string& Player::name() const {
    return m_name;
}

void Player::reset_hand(){
    m_card_c = 0;
    // free the memory!
    delete [] m_card_v;
    m_card_v = nullptr;
}

// this class will handle the card
void Player::add_card(const Card& new_card){
    // allocate new, larger mem
    // (one larger than before)
    Card* new_cards = new Card[m_card_c + 1];

    // copy cards over to new mem
    for (int i = 0; i < m_card_c; i++) {
        *(new_cards + i) = *(m_card_v + i);
    }
    
    // add new card to new mem
    *(new_cards + m_card_c) = new_card;
    
    // free old mem
    delete [] m_card_v;
    m_card_v = new_cards; // set to new mem

    // update card_c
    m_card_c++;
}


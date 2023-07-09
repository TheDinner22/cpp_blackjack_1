#include <array>
#include <exception>
#include <string>
#include "player.h"

const char* suit_to_string(Suit s){
    switch (s) {
        case DIAMONDS:
            return "diamonds";
        case HEARTS:
            return "hearts";
        case SPADES:
            return "spades";
        case CLUBS:
            return "clubs";
        default:
            throw "unreachable";
    }
}

const char* card_val_to_string(int v){
    switch (v) {
        case 1:
            return "ace";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "jack";
        case 12:
            return "queen";
        case 13:
            return "king";
        default:
            throw "unreachable";
    }
}

// ace of diamonds by default
Card::Card() : m_suit(DIAMONDS), m_value(1) {}

Card::Card(int value, Suit suit){
    if (value < 1 || value > 13) {
        throw "m_value was out of range";
    }

    m_value = value;
    m_suit = suit;
}

// you need to delete the pointer you get once you are done with it!
std::string* Card::name(){
    const char* card_name = card_val_to_string(m_value);
    const char* card_suit = suit_to_string(m_suit);

    std::string* card_title = new std::string(card_name);
    *card_title += " of ";
    *card_title += card_suit;

    return card_title;
}

int Card::value(){
    return m_value;
}

int Player::card_total() const {
    int total = 0;
    for (int i = 0; i < m_card_c; i++) {
        total += (m_card_v + i)->value();
    }
    return total;
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
    m_card_v = nullptr;
    
    // update card_c
    m_card_c++;
}

// you are responsible for this array pointer pointer
std::array<Card, 52>* make_unshuffled_deck(){
    std::array<Card, 52>* deck = new std::array<Card, 52>;

    Suit all[4] = {DIAMONDS, HEARTS, CLUBS, SPADES};
    for (int i = 0; i < 4; i++) {
        Suit s = all[i];
        for (int j = 1; j < 14; j++) {
             (*deck)[j*(i+1)] = Card(j, s);
        }
    }
    return deck;
}

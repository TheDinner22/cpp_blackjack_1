#include <exception>
#include <string>
#include "player.h"

class Player {};

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


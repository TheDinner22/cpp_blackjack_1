#include <set>
#include <vector>
#include <iostream>
#include "./deck.h"

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
Card::Card() : m_suit(DIAMONDS), m_value(1), m_name("ace of diamonds") {}

Card::Card(int value, Suit suit){
    if (value < 1 || value > 13) {
        throw "m_value was out of range";
    }

    m_value = value;
    m_suit = suit;

    // what is its name?
    const char* card_name = card_val_to_string(m_value);
    const char* card_suit = suit_to_string(m_suit);

    // build the name and assign to m_name
    std::string card_title = std::string(card_name);
    card_title += " of ";
    card_title += card_suit;
    m_name = card_title;
}

const std::string& Card::name() const {
    return m_name;
}

int Card::value() const {
    return m_value;
}

std::vector<Card> Deck::generate_cards(){
    std::vector<Card> deck;
    const int NUMBER_OF_SUITS = 4;
    const int NUMBER_OF_CARDS = 13;
    Suit all_suits[NUMBER_OF_SUITS] = {DIAMONDS, HEARTS, CLUBS, SPADES};
    for (int i = 0; i < NUMBER_OF_SUITS; i++) {
        for (int j = 0; j < NUMBER_OF_CARDS; j++) {
            deck.push_back(Card(j+1, all_suits[i]));
        }
    }

    return deck;
}

// https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
int Deck::generate_random_number(){
    return rand() % m_deck.size();
}

void Deck::reset(){
    // reset vec
    m_deck.clear();
    m_deck = generate_cards();
    // reset set
    m_used_cards.clear();
}

const Card& Deck::draw_card(){
    // getting a random number which has not yet been
    // used
    int card_index;
    while (true) {
        int possible_random = generate_random_number();
        const bool contains = m_used_cards.find(possible_random) != m_used_cards.end();
        if (!contains) {
            card_index = possible_random;
            break;
        }
    }

    m_used_cards.insert(card_index);
    return m_deck[card_index];
}

// for debugging
void Deck::print() const {
    for (int i = 0; i < 52; i++) {
        std::cout << m_deck[i].name() << std::endl;
    }
}


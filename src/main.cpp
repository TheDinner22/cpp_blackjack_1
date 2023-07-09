#include <array>
#include <iostream>
#include <string>
#include "io/io.h"
#include "player/player.h"

int main(){
    std::string* a = input("enter ur name:");
    std::cout << *a << std::endl;
    delete a;

    Card cool = Card(6, HEARTS);
    std::string* card_name = cool.name();
    std::cout << *card_name << std::endl;

    // player handles the pointer
    Player p(card_name);


    // make a deck and print it
    std::array<Card, 52>* deck = make_unshuffled_deck();

    for (int i = 0; i < 52; i++) {
        std::cout << std::endl;
        std::cout << *(*deck)[i].name() << std::endl;
    }

    delete deck;
}

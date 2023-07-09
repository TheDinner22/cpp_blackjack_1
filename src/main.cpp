#include <array>
#include <iostream>
#include <string>
#include "io/io.h"
#include "player/player.h"
#include "deck/deck.h"

void test_deck() {
    Deck d;

    std::cout << d.draw_card().name() << std::endl;
    std::cout << d.draw_card().name() << std::endl;
    std::cout << d.draw_card().name() << std::endl;

}

void test_input() {
    std::string a = input("enter ur name:");
    std::cout << a << std::endl;
}

void test_card_name() {
    Card cool = Card(6, HEARTS);
    const std::string& card_name = cool.name();
    std::cout << card_name << std::endl;
}

void test_player_creation (){
    Player p("guy named joe");
    p.print_hand();
    p.add_card(Card(1, HEARTS));
    p.print_hand();
    p.reset_hand();
    p.print_hand();
    
    p.add_card(Card(10, HEARTS));
    p.add_card(Card(12, DIAMONDS));
    p.print_hand();
    std::cout << p.card_total() << std::endl;
}

int main(){
    // test_input();

    // test_card_name();

    // test_player_creation();

    test_deck();
}

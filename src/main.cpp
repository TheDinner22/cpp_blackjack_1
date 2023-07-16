#include <array>
#include <iostream>
#include <string>
#include <vector>
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
    const int MAX_PLAYERS = 5;
    // welcome message and how many players
    std::cout << "Welcome to my garbage blackjack game!" << std::endl;
    std::string user_input = input("How many players");
    // https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
    int number_of_players = atoi( user_input.c_str() );

    if (number_of_players < 1 || number_of_players > MAX_PLAYERS) {
        std::cout << "invalid input!";
        return 1;
    }

    // make players
    std::vector<Player> players;
    for (int i = 0; i < number_of_players; i++) {
        std::cout << "what is player " << i+1 << "s name?" << std::endl;
        std::string name = input("");
        players.push_back(Player(name));
    }

    // make deck
    Deck deck = Deck();

    while (true) {
        // deal everyone their cards, starting with the dealer
        const Card& dealers_shown_card = deck.draw_card();
        const Card& dealers_hidden_card = deck.draw_card();
        std::cout << "the dealer is showing a " << dealers_shown_card.name() << std::endl;

        for (int i = 0; i < number_of_players; i++) {
            const Card& card1 = deck.draw_card();
            const Card& card2 = deck.draw_card();
            players[i].add_card(card1);
            players[i].add_card(card2);
            players[i].print_hand();
        }

        // end of turn reset deck and player hands
        deck.reset();
        for (int i = 0; i < number_of_players; i++) {
            players[i].reset_hand();
        }
    }
}

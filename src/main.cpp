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
        std::cout << "what is player " << i+1 << "'s name?" << std::endl;
        std::string name = input("");
        players.push_back(Player(name));
    }

    // make deck
    Deck deck = Deck();

    while (true) {
        // deal everyone their cards, starting with the dealer
        Player dealer = Player("dealer");
        const Card& card1 = deck.draw_card();
        std::cout << "the dealer is showing a " << card1.name() << std::endl;
        dealer.add_card(card1);
        dealer.add_card(deck.draw_card());

        for (int i = 0; i < number_of_players; i++) {
            const Card& card1 = deck.draw_card();
            const Card& card2 = deck.draw_card();
            players[i].add_card(card1);
            players[i].add_card(card2);
        }

        // players turns WIP
        for (int i = 0; i < number_of_players; i++) {
            std::cout << "it is " << players[i].name() << "'s turn" << std::endl;
            std::cout << "here is your hand" << std::endl;
            players[i].print_hand();
            std::string user_input = input("hit or stand (h/s)?");
            if (user_input == "hit" || user_input == "h") {
                std::cout << "you hit" << std::endl;
            }
            else if (user_input == "stand" || user_input == "s") {
                std::cout << "you stand" << std::endl;
            }
            else {
                std::cout << "invalid choice" << std::endl;
                return 1;
            }
        }

        // dealers turn
        std::cout << std::endl << "-----------------dealers turn-----------------" << std::endl << std::endl;
        while (true) {
            if (dealer.card_total() > 21) {
                std::cout << "the dealer is bust!" << std::endl;
                break;
            }
            std::cout << "dealer has a total of " << dealer.card_total() << std::endl;
            // hit
            if (dealer.card_total() < 17) {
                const Card& new_card = deck.draw_card();
                std::cout << "the dealer hits on " << dealer.card_total() << "!" << std::endl;
                std::cout << "the dealer draws a " << new_card.name() << "!" << std::endl;
                dealer.add_card(new_card);
            }
            // stand
            else {
                std::cout << "the dealer stands on " << dealer.card_total() << std::endl;
                break;
            }
        }

        // end of turn reset deck and player hands
        // and dealers hand
        deck.reset();
        dealer.reset_hand();
        for (int i = 0; i < number_of_players; i++) {
            players[i].reset_hand();
        }
    }
}

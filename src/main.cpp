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
    delete card_name;
}

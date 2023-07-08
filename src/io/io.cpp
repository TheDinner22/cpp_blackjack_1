#include <iostream>
#include <string>

std::string input(const char* prompt){
    std::cout << prompt << std::endl;

    std::string buffer;
    std::getline(std::cin, buffer); //WARN idk this function
    
    return buffer;
}

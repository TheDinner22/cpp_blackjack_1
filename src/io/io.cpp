#include <iostream>
#include <string>

// returns a pointer which YOU are responsible for
std::string input(const char* prompt){
    std::cout << prompt << std::endl;

    std::string buffer;
    std::getline(std::cin, buffer); //WARN idk this function
    
    return buffer;
}

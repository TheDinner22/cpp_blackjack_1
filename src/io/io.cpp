#include <iostream>
#include <string>

// returns a pointer which YOU are responsible for
// you need to delete it when you are done
// with it
std::string* input(const char* prompt){
    std::cout << prompt << std::endl;

    std::string* buffer = new std::string;
    std::getline(std::cin, *buffer); //WARN idk this function
    
    return buffer;
}

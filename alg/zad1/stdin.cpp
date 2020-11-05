#include <iostream>
#include <string>

int main() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << "stdin"<<line << std::endl;
    }
    return 0;
}
#include <fstream>
#include <iostream>
#include "libs/Planet.hpp"
#include "libs/hohmann.hpp"
#include "libs/splashCalc.hpp"

int main() {
    while (true) {
        std::cout << constants::menu << std::endl;
        int input;
        std::cin >> input;
        if (input == 1) hohmann::run();
        if (input == 2) splashCalc::run();
        if (input == 3) break;
    }

}

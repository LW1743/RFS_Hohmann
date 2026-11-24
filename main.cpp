#include <iostream>
#include "libs/Planet.hpp"

int main() {
    double ms = planets::earth.escape_velocity();
    std::cout << ms << std::endl;
    return 0;
}

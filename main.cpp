#include <iostream>
#include "libs/Planet.hpp"
#include "libs/hohmann.hpp"

/*TODO
 * Test for stupid altitudes
 * Make Loop for the txt file
 */

int main() {
    double V1 = hohmann::calculateRequiredDeltaV1(450000, 900000, planets::earth);
    double V2 = hohmann::calculateRequiredDeltaV2(450000, 900000, planets::earth);
    double VTotal = hohmann::calculateRequiredDeltaVTotal(450000, 900000, planets::earth);
    std::cout << V1 << std::endl;
    std::cout << V2 << std::endl;
    std::cout << VTotal << std::endl;
    return 0;
}

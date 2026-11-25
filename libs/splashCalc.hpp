//
// Created by lukas on 25/11/2026.
//

#ifndef RFS_HOHMANN_SPLASHCALC_H
#define RFS_HOHMANN_SPLASHCALC_H
#include <utility>

#include "hohmann.hpp"

class splashCalc {
private:
    std::string name_;
    double radius_m_;
    double gravity_mps2_;
    double mass_;
public:

    static double calculateRequiredDeltaVForSplashdown(double startAltM, Planet p) {
        return hohmann::calculateRequiredDeltaV1(startAltM, 50000, std::move(p));
    }

    static int run() {
        double currentAlt, deltaV;
        std::cout << "Please enter current altitude in m" << std::endl;
        std::cin >> currentAlt;
        deltaV = calculateRequiredDeltaVForSplashdown(currentAlt, planets::earth);

        
    }

};
#endif //RFS_HOHMANN_SPLASHCALC_H

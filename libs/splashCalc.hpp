//
// Created by lukas on 25/11/2026.
//

#ifndef RFS_HOHMANN_SPLASHCALC_H
#define RFS_HOHMANN_SPLASHCALC_H
#include <utility>

#include "hohmann.hpp"

//NOTE TO SELF: Negative Delta V means slowing down

class splashCalc {
private:
    std::string name_;
    double radius_m_;
    double gravity_mps2_;
    double mass_;
public:

    static double calculateRequiredFuelInKG(double c, double m0, double deltaV) {
        //Calculate mT using Tsiolkovsky
        double m1 = m0 * std::exp(- std::abs(deltaV) / c);
        return m0 - m1;
    }

    static double calculateRequiredDeltaVForSplashdown(double startAltM, Planet p) {
        return hohmann::calculateRequiredDeltaV1(startAltM, 50000, std::move(p));
    }

    static int run() {

        //create outfile
        std::ofstream outFile;
        outFile.open("splash.txt");

        //vars
        double currentAlt, m0, deltaV, c, fuel;
        std::string input;

        //Enter Values
        std::cout << "Please enter current altitude in m" << std::endl;
        std::cin >> currentAlt;
        std::cout << "Please enter starting mass in kg" << std::endl;
        std::cin >> m0;
        std::cout << "Please enter exit velocity" << std::endl;
        std::cin >> c;
        std::cout << "Write to file splash.txt? (y/N)" << std::endl;
        std::cin >> input;

        //Calculate
        deltaV = calculateRequiredDeltaVForSplashdown(currentAlt, planets::earth);
        fuel = calculateRequiredFuelInKG(c, m0, deltaV);

        //Saves to file when answer was "y"
        if (input == "y") {
            outFile << "Current Altitude in m:\t" << currentAlt << std::endl;
            outFile << "Mass in kg: \t\t\t" << m0 << std::endl;
            outFile << "Exit Velocity: \t\t\t" << c << std::endl;
            outFile <<  "Required deltaV: \t\t" << std::abs(deltaV) << std::endl;
            outFile << "Required fuel: \t\t\t" << fuel << std::endl;
        }

        //Print results
        std::cout << "Required deltaV:\t " << std::abs(deltaV) << std::endl;
        std::cout << "Required fuel:\t\t " << fuel << std::endl;
    }

};
#endif //RFS_HOHMANN_SPLASHCALC_H

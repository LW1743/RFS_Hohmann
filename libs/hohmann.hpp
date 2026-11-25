//
// Created by lukas on 24/11/2026.
//

#ifndef RFS_HOHMANN_HOHMANN_H
#define RFS_HOHMANN_HOHMANN_H
#include "Planet.hpp"


class hohmann {
public:
    //r1 and r2 are alt above surface
    static double calculateRequiredDeltaV1 (double r1AboveSurface, double r2AboveSurface, Planet planet) {

        /* Checking for Dumb Inputs
         * Return Values explained:
         * -1 = r1 below Planet Surface
         * -2 = r2 below Planet Surface
         * -3 = deltaV above Escape Velocity
        */

        if (r1AboveSurface <= 0) {
            std::cerr << "r1 is below Planet Surface for Planet " << planet.name() << std::endl;
            return -1;
        }
        if (r2AboveSurface <= 0) {
            std::cerr << "r2 is below Planet Surface for Planet " << planet.name() << std::endl;
            return -2;
        }

        double r1 = r1AboveSurface + planet.radius();
        double r2 = r2AboveSurface + planet.radius();
        double deltaV1 = std::sqrt((constants::G*planet.mass())/(r1)) * (std::sqrt((2* r2)/(r1+r2)) -1 ); // sqrt(GM/r1) * (sqrt(2 * r2 / (r1 + r2) ) - 1) to calculate the delta V for entering elliptical transfer orbit

        if (deltaV1 >= planet.escape_velocity()) {
            return -3;
        }

        return deltaV1;
    }
    static double calculateRequiredDeltaV2 (double r1AboveSurface, double r2AboveSurface, Planet planet) {

        /* Checking for Dumb Inputs
         * Return Values explained:
         * -1 = r1 below Planet Surface
         * -2 = r2 below Planet Surface
         * -3 = deltaV above Escape Velocity
        */

        if (r1AboveSurface <= 0) {
            std::cerr << "r1 is below Planet Surface for Planet " << planet.name() << std::endl;
            return -1;
        }
        if (r2AboveSurface <= 0) {
            std::cerr << "r2 is below Planet Surface for Planet " << planet.name() << std::endl;
            return -2;
        }

        double r1 = r1AboveSurface + planet.radius();
        double r2 = r2AboveSurface + planet.radius();
        double deltaV2 = std::sqrt((constants::G*planet.mass())/(r2)) * (1 - std::sqrt((2* r1)/(r1+r2))); // sqrt(GM/r2) * (1 - sqrt(2 * r1 / (r1 + r2) )) to calculate the delta V for exiting elliptical transfer orbit

        if (deltaV2 >= planet.escape_velocity()) {
            return -3;
        }
        return deltaV2;
    }

    static double calculateRequiredDeltaVTotal (double r1AboveSurface, double r2AboveSurface, Planet planet) {
        return calculateRequiredDeltaV1(r1AboveSurface,r2AboveSurface,planet) + calculateRequiredDeltaV2(r1AboveSurface,r2AboveSurface,planet);
    }

    static int run() {
        std::ofstream outFile;
        outFile.open("hohmann.txt");

        double startAlt, endAlt;
        std::string input;

        std::cout << "Please enter Start Altitude in m" << std::endl;
        std::cin >> startAlt;
        std::cout << "Please enter End Altitude in m" << std::endl;
        std::cin >> endAlt;
        std::cout << "Write to file hohmann.txt? (y/N)" << std::endl;
        std::cin >> input;
        if (input == "y") {
            /* Print to outFile */
            outFile << "Start Altitude in m: " << startAlt << std::endl;
            outFile << "End Altitude in m:\t" << endAlt << std::endl;

            for (Planet p : planets::planets) {
                double V1 = hohmann::calculateRequiredDeltaV1(startAlt, endAlt, p);
                double V2 = hohmann::calculateRequiredDeltaV2(startAlt, endAlt, p);
                double VTotal = hohmann::calculateRequiredDeltaVTotal(startAlt, endAlt, p);
                outFile << p.name() << std::endl;
                outFile << "Required V1:\t\t" << V1 << std::endl;
                outFile << "Required V2:\t\t" << V2 << std::endl;
                outFile << "Required VTotal:\t" << VTotal << std::endl;
            }
        }
        for (Planet p : planets::planets) {
            double V1 = hohmann::calculateRequiredDeltaV1(startAlt, endAlt, p);
            double V2 = hohmann::calculateRequiredDeltaV2(startAlt, endAlt, p);
            double VTotal = hohmann::calculateRequiredDeltaVTotal(startAlt, endAlt, p);
            std::cout << p.name() << std::endl;
            std::cout << "Required V1:\t\t" << V1 << std::endl;
            std::cout << "Required V2:\t\t" << V2 << std::endl;
            std::cout << "Required VTotal:\t" << VTotal << std::endl;
        }

        return 0;
    }

};


#endif //RFS_HOHMANN_HOHMANN_H

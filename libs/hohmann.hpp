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
        double r1 = r1AboveSurface + planet.radius();
        double r2 = r2AboveSurface + planet.radius();
        double deltaV1 = std::sqrt((constants::G*planet.mass())/(r1)) * (std::sqrt((2* r2)/(r1+r2)) -1 ); // sqrt(GM/r1) * (sqrt(2 * r2 / (r1 + r2) ) - 1) to calculate the delta V for entering elliptical transfer orbit
        return deltaV1;
    }
    static double calculateRequiredDeltaV2 (double r1AboveSurface, double r2AboveSurface, Planet planet) {
        double r1 = r1AboveSurface + planet.radius();
        double r2 = r2AboveSurface + planet.radius();
        double deltaV2 = std::sqrt((constants::G*planet.mass())/(r2)) * (1 - std::sqrt((2* r1)/(r1+r2))); // sqrt(GM/r2) * (1 - sqrt(2 * r1 / (r1 + r2) )) to calculate the delta V for exiting elliptical transfer orbit
        return deltaV2;
    }

    static double calculateRequiredDeltaVTotal (double r1AboveSurface, double r2AboveSurface, Planet planet) {
        return calculateRequiredDeltaV1(r1AboveSurface,r2AboveSurface,planet) + calculateRequiredDeltaV2(r1AboveSurface,r2AboveSurface,planet);
    }

};


#endif //RFS_HOHMANN_HOHMANN_H

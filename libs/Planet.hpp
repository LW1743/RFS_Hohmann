//
// Created by lukas on 24/11/2026.
//
#ifndef RFS_HOHMANN_PLANET_H
#define RFS_HOHMANN_PLANET_H
#include <string>
#include <cmath>
#include <utility>
#include "constants.hpp"

class Planet {
private:
    std::string name_;
    double radius_m_;
    double gravity_mps2_;
    double mass_;
public:
    Planet(std::string name, double radius_m, double mass)
        : name_(std::move(name)), radius_m_(radius_m), mass_(mass) {
        gravity_mps2_ = (constants::G * mass_) / (radius_m_*radius_m_);
    }

    std::string name() {return name_;};
    double radius() {return radius_m_;};
    double gravity() {return gravity_mps2_;};
    double mass() {return mass_;};

    double escape_velocity() {
        return std::sqrt(2.0 * gravity_mps2_ * radius_m_);
    }
};

namespace planets {
    /*
     *Values from https://nssdc.gsfc.nasa.gov/planetary/factsheet/
     * name = Planet Name
     * radius_m = Equatorial Radius of the Planet in m
     * mass = Planet Mass in kg
     */
    inline Planet venus{"Venus", 6051800, 4.8673e24};
    inline Planet earth{"Earth", 6371000, 5.9722e24};
    inline Planet mars{"Mars", }
}


#endif //RFS_HOHMANN_PLANET_H

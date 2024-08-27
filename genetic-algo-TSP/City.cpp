#include "City.hpp"
#include <cmath>
#include <random>
#include <iostream>

// Static method for generating a random double
double City::randomDouble(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

City::City(const std::string& cityName) : name(cityName) {
    xCoor = randomDouble(MIN, MAX);
    yCoor = randomDouble(MIN, MAX);
}

double City::getXCoor() const {
    return xCoor;
}

double City::getYCoor() const {
    return yCoor;
}

const std::string& City::getName() const {
    return name;
}

City::~City() {
//    cout<<"city destroyed"<<endl;
}


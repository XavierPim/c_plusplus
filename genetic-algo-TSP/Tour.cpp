#include "Tour.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

Tour::Tour() : fitness(ZEROD) {}

Tour::Tour(const vector<shared_ptr<City>>& cities) : fitness(ZEROD) {
    makeRandomTour(cities);
    calcFitness();
}

double Tour::getFitness() const {
    return fitness;
}

void Tour::calcFitness() {
    fitness = ZEROD;
    for (size_t i = ZERO; i < tour.size(); ++i) {
        shared_ptr<City> current = tour[i];
        shared_ptr<City> next = tour[(i + ONE) % tour.size()];
        fitness += calculateDistance(*current, *next);
    }
}

double Tour::calculateDistance(const City& city1, const City& city2) {
    double dx = city1.getXCoor() - city2.getXCoor();
    double dy = city1.getYCoor() - city2.getYCoor();
    return sqrt(dx * dx + dy * dy);
}

void Tour::makeRandomTour(const vector<shared_ptr<City>>& cities) {
    tour = cities; // Copy the vector
    random_device rd;
    mt19937 g(rd());
    shuffle(tour.begin(), tour.end(), g); // Shuffle the tour
}

ostream& operator<<(ostream& os, const Tour& tour) {
    for (const auto& city : tour.tour) {
        os << city->getName() << " -> ";
    }
//    os << "\nTotal fitness: " << tour.fitness << endl;
    return os;
}

const vector<shared_ptr<City>> &Tour::getTour() const {
    return tour;
}

void Tour::addCity(const shared_ptr<City>& city) {
    tour.push_back(city);
}

void Tour::mutateTour(){
    size_t numCities = tour.size();
    if (numCities < TWO) {
        return;
    }

  RAND;
    std::uniform_int_distribution<> diceRoll(ONE, SIX);

    // Loop through each city in the tour
    for (size_t i = ZERO; i < numCities; ++i) {
        // Roll the dice
        int roll = diceRoll(gen);

        // If the roll is a 1, perform the swap
        if (roll == ONE) {
            // Determine neighbor index - wrap to first city if it's the last city
            size_t neighborIndex = (i + ONE) % numCities;
            std::swap(tour[i], tour[neighborIndex]);
        }
    }
    calcFitness();
}

Tour::~Tour() {
//cout<< "tour destroyed"<< endl;
}

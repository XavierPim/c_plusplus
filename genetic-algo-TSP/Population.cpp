#include "Population.hpp"
#include <algorithm>
#include <iostream>

Population::Population() {}

Population::Population(const std::vector<std::shared_ptr<City>> &cities, std::size_t numTours) {
    for (std::size_t i = ZERO; i < numTours; ++i) {
        std::shared_ptr<Tour> newTour = std::make_shared<Tour>(cities);
        newTour->calcFitness();
        population.push_back(newTour);
    }
    findElite();
}

std::shared_ptr<Tour> Population::findElite() {
    if (population.empty()) {
        return nullptr;
    }

    size_t eliteIndex = ZERO;  // Initialize index for the elite tour

    for (size_t i = ZERO; i < population.size(); ++i) {
        // Check if a better (lower fitness) tour is found
        if (elite == nullptr || population[i]->getFitness() < elite->getFitness()) {
            elite = population[i];
            eliteIndex = i;  // Update the elite index
        }
    }

    // If elite tour is not already at the ZEROth index, swap it
    if (eliteIndex != ZERO) {
        swap(population[ZERO], population[eliteIndex]);
    }

    // Reset bestNonElite to null before finding the new best non-elite
    bestNonElite = nullptr;

    for (size_t i = ZERO; i < population.size(); ++i) {
        // Check if it's better than the current bestNonElite and not equal to elite
        if ((bestNonElite == nullptr || population[i]->getFitness() < bestNonElite->getFitness()) && i != eliteIndex) {
            bestNonElite = population[i];
        }
    }

    return elite;
}




const std::vector<std::shared_ptr<Tour>> &Population::getPopulation() const {
    return population;
}

void Population::addTour(const std::shared_ptr<Tour>& tour) {
    population.push_back(tour);
}

const shared_ptr<Tour> &Population::getElite() const {
    return elite;
}

ostream &operator<<(ostream &os, const Population &population) {
    for (const auto& tour : population.population) {
        os << *tour << endl;
    }
    return os;
}

const shared_ptr<Tour> &Population::getBestNonElite() const {
    return bestNonElite;
}

Population::~Population() {
//cout<<"population deleted"<< endl;
}




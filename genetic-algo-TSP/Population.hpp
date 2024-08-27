#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <memory>
#include <vector>
#include "Tour.hpp"

class Population {
private:
    vector<shared_ptr<Tour>> population;
    shared_ptr<Tour> elite;
    shared_ptr<Tour> bestNonElite = nullptr;
    enum {ZERO};

public:
    ~Population();

    /**
     * SUMMARY: Retrieves the best non-elite tour from the population.
     * PRE: None.
     * POST: None.
     * RETURN: Returns a shared pointer to the best non-elite Tour object.
     */
    const shared_ptr<Tour> &getBestNonElite() const;

    /**
     * SUMMARY: Retrieves the elite tour from the population.
     * PRE: None.
     * POST: None.
     * RETURN: Returns a shared pointer to the elite Tour object.
     */
    const shared_ptr<Tour> &getElite() const;

    /**
     * SUMMARY: Default constructor for the Population class.
     * PRE: None.
     * POST: Initializes an empty Population object.
     * RETURN: None.
     */
    Population();

    /**
     * SUMMARY: Constructs a Population object with a given set of cities and number of tours.
     * PRE: Requires a vector of shared_ptr<City> representing the cities, and a size_t indicating the number of tours.
     * POST: Creates a Population object with the specified number of tours using the given cities.
     * RETURN: None.
     */
    explicit Population(const vector<shared_ptr<City>>& cities, size_t numTours);

    /**
     * SUMMARY: Retrieves the population as a vector of shared pointers to Tour objects.
     * PRE: None.
     * POST: None.
     * RETURN: Returns a constant reference to a vector of shared_ptr<Tour>.
     */
    const vector<shared_ptr<Tour>>& getPopulation() const;

    /**
     * SUMMARY: Adds a tour to the population.
     * PRE: Takes a shared_ptr<Tour> representing the tour to be added.
     * POST: Adds the tour to the population.
     * RETURN: None.
     */
    void addTour(const shared_ptr<Tour>& tour);

    /**
     * SUMMARY: Finds and sets the elite tour in the population.
     * PRE: None.
     * POST: Updates the elite member with the tour having the best fitness in the population.
     * RETURN: Returns a shared pointer to the elite Tour object.
     */
    shared_ptr<Tour> findElite();

    /**
     * SUMMARY: Overloads the << operator for printing Population objects.
     * PRE: Requires an ostream object and a Population object.
     * POST: Outputs the Population object to the provided ostream.
     * RETURN: Returns a reference to the ostream object.
     */
    friend ostream& operator<<(ostream& os, const Population& population);
};

#endif // POPULATION_HPP

#ifndef TOUR_HPP
#define TOUR_HPP
#define RAND     random_device rd; mt19937 gen(rd());
#include <memory>
#include <vector>
#include "City.hpp"
constexpr double ZEROD = 0.0;
using namespace std;

class Tour {
private:
    double fitness;
    std::vector<std::shared_ptr<City>> tour;
    enum {ZERO,ONE,TWO,SIX=6};

public:
    ~Tour();
    /**
     * SUMMARY: Retrieves the tour as a vector of shared pointers to City objects.
     * PRE: None.
     * POST: None.
     * RETURN: Returns a constant reference to a vector of shared_ptr<City>.
     */
    const std::vector<std::shared_ptr<City>> &getTour() const;

    /**
     * SUMMARY: Default constructor for the Tour class.
     * PRE: None.
     * POST: Creates a Tour object with default values.
     * RETURN: None.
     */
    Tour();


    /**
     * SUMMARY: Constructs a Tour object with a given set of cities.
     * PRE: Takes a vector of shared_ptr<City> representing the cities in the tour.
     * POST: Creates a Tour object with the provided cities.
     * RETURN: None.
     */
    explicit Tour(const std::vector<std::shared_ptr<City>>& cities);

    /**
     * SUMMARY: Retrieves the fitness of the tour.
     * PRE: None.
     * POST: None.
     * RETURN: Returns the fitness as a double.
     */
    double getFitness() const;

    /**
     * SUMMARY: Calculates the fitness of the tour.
     * PRE: None.
     * POST: Updates the fitness of the tour based on some criteria (e.g., total distance).
     * RETURN: None.
     */
    void calcFitness();

    /**
     * SUMMARY: Calculates the Euclidean distance between two cities.
     * PRE: Requires two City objects.
     * POST: None.
     * RETURN: Returns the Euclidean distance as a double.
     */
    static double calculateDistance(const City& city1, const City& city2);

    /**
     * SUMMARY: Generates a random tour from a given set of cities.
     * PRE: Takes a vector of shared_ptr<City> representing the cities.
     * POST: Randomizes the tour order.
     * RETURN: None.
     */
    void makeRandomTour(const std::vector<std::shared_ptr<City>>& cities);

    /**
     * SUMMARY: Adds a city to the tour.
     * PRE: Takes a shared_ptr<City> representing the city to be added.
     * POST: Adds the city to the tour.
     * RETURN: None.
     */
    void addCity(const std::shared_ptr<City>& city);

    /**
     * SUMMARY: Mutates the tour by modifying its order or structure.
     * PRE: None.
     * POST: Alters the tour in some manner (e.g., swapping cities).
     * RETURN: None.
     */
    void mutateTour();

    /**
     * SUMMARY: Overloads the << operator for printing Tour objects.
     * PRE: Requires an ostream object and a Tour object.
     * POST: Outputs the Tour object to the provided ostream.
     * RETURN: Returns a reference to the ostream object.
     */
    friend std::ostream& operator<<(std::ostream& os, const Tour& tour);
};

#endif // TOUR_HPP

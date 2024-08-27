#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <random>
using namespace std;

class City {
private:
    std::string name;
    double xCoor;
    double yCoor;
    static constexpr int MIN = 0;
    static constexpr int MAX = 1000;

    /**
     * SUMMARY: Generates a random double value between min and max.
     * PRE: Requires minimum and maximum integer values for the range.
     * POST: None.
     * RETURN: Returns a random double value within the specified range.
     */
    static double randomDouble(int min, int max);

public:
    /**
     * SUMMARY: Constructs a city with a given name and random coordinates.
     * PRE: Takes a string representing the city's name.
     * POST: City object created with a specified name and random coordinates.
     * RETURN: None.
     */
    explicit City(const std::string& cityName);

    /**
     * SUMMARY: Default destructor for the City class.
     * PRE: None.
     * POST: City object is destroyed.
     * RETURN: None.
     */
    ~City();

    /**
     * SUMMARY: Retrieves the X coordinate of the city.
     * PRE: None.
     * POST: None.
     * RETURN: Returns the X coordinate as a double.
     */
    double getXCoor() const;

    /**
     * SUMMARY: Retrieves the Y coordinate of the city.
     * PRE: None.
     * POST: None.
     * RETURN: Returns the Y coordinate as a double.
     */
    double getYCoor() const;

    /**
     * SUMMARY: Retrieves the name of the city.
     * PRE: None.
     * POST: None.
     * RETURN: Returns the name of the city as a constant string reference.
     */
    const std::string& getName() const;
};

#endif // CITY_HPP


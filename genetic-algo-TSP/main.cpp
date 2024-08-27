// Name: Roy (Xavier) Pimentel
// Student#: A00697839
#include "GeneticAlgo.hpp"
#include <memory>
#include <vector>
#include <iostream>

int main() {
    vector<shared_ptr<City>> defaultCities = {
            make_shared<City>("A"),
            make_shared<City>("B"),
            make_shared<City>("C"),
            make_shared<City>("D"),
            make_shared<City>("E"),
            make_shared<City>("F"),
            make_shared<City>("G"),
            make_shared<City>("H"),
            make_shared<City>("I"),
            make_shared<City>("J"),
            make_shared<City>("K"),
            make_shared<City>("L"),
            make_shared<City>("M"),
            make_shared<City>("N"),
            make_shared<City>("O"),
            make_shared<City>("P"),
            make_shared<City>("Q"),
            make_shared<City>("R"),
            make_shared<City>("S"),
            make_shared<City>("T"),
            make_shared<City>("U"),
            make_shared<City>("V"),
            make_shared<City>("W"),
            make_shared<City>("X"),
            make_shared<City>("Y"),
            make_shared<City>("Z"),
            make_shared<City>("AA"),
            make_shared<City>("BB"),
            make_shared<City>("CC"),
            make_shared<City>("DD"),
            make_shared<City>("EE")
    };

    // Get the instance of GeneticAlgo
    GeneticAlgo* algo = GeneticAlgo::getInstance();

    // Prompt for and set up the algorithm parameters
    size_t numberOfTours;
    int iterations;
    double improvementFactor;

    cout << "Enter the number of tours: ";
    cin >> numberOfTours;

    cout << "Enter how many iterations for GeneticAlgo: ";
    cin >> iterations;

    cout << "Enter the desired improvement factor: ";
    cin >> improvementFactor;


    // Initialize the algorithm with cities
    algo->setup(defaultCities, improvementFactor, numberOfTours);

    // Execute the algorithm
    algo->run(iterations);

    algo->generateReport();
    return 0;
}

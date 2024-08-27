#ifndef GENETICALGO_HPP
#define GENETICALGO_HPP

#include <memory>
#include <vector>
#include "City.hpp"
#include "Population.hpp"
#define RAND     random_device rd; mt19937 gen(rd());
using namespace std;

class GeneticAlgo {
private:
    double base_distance = 0.0;
    double originalEliteDistance = 0.0;
    shared_ptr<Population> originalElite;
    size_t numTours;
    int inputIterations;
    int outputIterations;
    shared_ptr<Population> base_pop;
    double improvedBY;
    size_t permaNumTours;
    double improvementFactor;
    static GeneticAlgo* instance;

    /**
    * SUMMARY: PRIVATE Default constructor for GeneticAlgo class.
    * PRE: None.
    * POST: Initializes a new GeneticAlgo object with default values.
    * RETURN: None.
    */
    GeneticAlgo();
public:
    enum {ZERO,ONE,TWO,THREE, FIVE = 5,TEN=10};
    // Singleton methods
    GeneticAlgo(const GeneticAlgo&) = delete;
    void operator=(const GeneticAlgo&) = delete;

    static GeneticAlgo* getInstance();

    /**
        * SUMMARY: Begins execution of the genetic algorithm.
        * PRE: Assumes setup() has been called with an appropriate set of cities.
        * POST: Executes the genetic algorithm and updates base_pop based on the results.
        * RETURN: None.
        */
    void run(int input);

    /**
     * SUMMARY: Sets up the initial state of the genetic algorithm.
     * PRE: Requires a vector of shared_ptr<City> representing the cities for the genetic algorithm.
     * POST: Prepares the initial population for the genetic algorithm.
     * RETURN: None.
     */
    void setup(const vector<shared_ptr<City>> &cities, double inputImprov, size_t numTours);

    /**
     * SUMMARY: Performs crossover operation on a given population to create a new population.
     * PRE: Takes a shared_ptr<Population> as input representing the current population.
     * POST: Generates a new population based on crossover of the input population.
     * RETURN: Returns a shared_ptr<Population> representing the new population.
     */
    shared_ptr<Population> crossOver(const shared_ptr<Population>& inputPop);

    /**
     * SUMMARY: Creates new children for the population by combining tours from parent populations.
     * PRE: Takes a shared_ptr<Population> for child population, input population, and a population index.
     * POST: Modifies the child population by adding new tours derived from the input population.
     * RETURN: None.
     */
    void eliteChildMaker(shared_ptr<Population>& child, const shared_ptr<Population>& inputPop, size_t popIndex);

    /**
     * SUMMARY: Merges two parent tours to create a new child tour.
     * PRE: Requires two shared_ptr<Tour>, representing the parent tours.
     * POST: Creates a new child tour based on the parents.
     * RETURN: Returns a shared_ptr<Tour> representing the new child tour.
     */
    shared_ptr<Tour> mergeParents(shared_ptr<Tour> &parent1, const shared_ptr<Tour> &parent2);

    /**
     * SUMMARY: Generates a random integer within a specified range.
     * PRE: Requires minimum and maximum integer values for the range.
     * POST: None.
     * RETURN: Returns a random integer within the given range.
     */
    int randomInt(int min, int max);

    /**
     * SUMMARY: Applies mutation to the tours in a given population.
     * PRE: Requires a shared_ptr<Population> representing the population to mutate.
     * POST: Mutates tours within the input population.
     * RETURN: None.
     */
    void tryMutate(const shared_ptr<Population> &inputPop);


    /**
     * SUMMARY: Calculates the improvement ratio of the new population compared to the base population.
     * PRE: Requires a shared_ptr<Population> representing the new population.
     * POST: Updates the improvedBY member based on the comparison between new and base populations.
     * RETURN: None.
     */
    void calculateImprovementRatio(const shared_ptr<Population> &newPop);

    /**
     * SUMMARY: Evaluates the current population and prints iteration results.
     * PRE: Requires a shared_ptr<Population> for evaluation and the current iteration number.
     * POST: Outputs the status of the current iteration and updates algorithm state.
     * RETURN: None.
     */
    void evaluate(const shared_ptr<Population> &newPop, size_t iteration);

    /**
     * SUMMARY: Generates a final report summarizing the results of the genetic algorithm.
     * PRE: Assumes that the genetic algorithm has been run to completion.
     * POST: Outputs a detailed report of the algorithm's performance.
     * RETURN: None.
     */
    void generateReport();


};

#endif // GENETICALGO_HPP

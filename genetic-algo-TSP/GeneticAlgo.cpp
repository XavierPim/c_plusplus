#include "GeneticAlgo.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_set>

GeneticAlgo::GeneticAlgo() {}

void GeneticAlgo::setup(const vector<shared_ptr<City>> &cities, double inputImprov, size_t inputNumTours) {
    numTours = inputNumTours;
    improvementFactor = inputImprov;
    base_pop = make_shared<Population>(cities, numTours);
    base_distance = base_pop->findElite()->getFitness();
    originalElite = base_pop;
    originalEliteDistance = base_distance;
}

void GeneticAlgo::run(int input) {
    inputIterations = input;
    int iterationCount = ONE;
    for (int i = ZERO; i < inputIterations; ++i) {

        shared_ptr<Population> newPopulation = crossOver(base_pop);
//        cout << "Print all base tours" << endl;
//        cout<<*base_pop<<endl;


//        cout << "Print crossOver tours" << endl;
//        cout << *newPopulation<< endl;

        tryMutate(newPopulation);

//        cout << "Print mutated tours" << endl;
//        cout << *newPopulation<< endl;



        // Update basePop for the next iteration
        newPopulation->findElite();

        //PRINTER FOR IMPROVEMENT CHECK
//      cout << *newPopulation->getElite()<< endl;
//      cout << newPopulation->getElite()->getFitness()<< endl;

        base_pop = newPopulation;

        evaluate(base_pop, iterationCount);
        if(improvedBY > improvementFactor){
            break;
        }
        iterationCount++;
    }
    outputIterations = iterationCount;
}

shared_ptr<Population> GeneticAlgo::crossOver(const shared_ptr<Population> &inputPop) {
    RAND;
    permaNumTours = numTours;
    // Shuffle the input population, excluding the elite at the 0th index
    vector<shared_ptr<Tour>> population = inputPop->getPopulation();
    if (population.size() > ONE) {
        shuffle(population.begin() + ONE, population.end(), gen);
    }

    // Create a new, empty population
    auto newPopulation = make_shared<Population>();

    // Continue the crossover process until the new population reaches the desired size
    while (newPopulation->getPopulation().size() < inputPop->getPopulation().size()) {
        eliteChildMaker(newPopulation, inputPop, ONE);

        //PRINTER numTours after each iteration in crossOver
//        cout << "remaining numTours after iteration" << endl;
//        cout << numTours << endl;
        numTours = permaNumTours;
    }

    return newPopulation;
}

void
GeneticAlgo::eliteChildMaker(shared_ptr<Population> &child, const shared_ptr<Population> &inputPop, size_t popIndex) {
    const vector<shared_ptr<Tour>> &population = inputPop->getPopulation();
    size_t popSize = population.size();
    size_t availTours = popSize - popIndex;
    size_t segmentSize = FIVE;
    auto parent1 = make_shared<Population>();
    auto parent2 = make_shared<Population>();

    if (child->getPopulation().size() == inputPop->getPopulation().size()) {
        return;
    }

    if (child->getPopulation().empty() || child->getPopulation()[ZERO] == nullptr) {
        shared_ptr<Tour> inputElite = inputPop->getElite();
        child->addTour(inputElite);
    }

//     Check if population size (excluding elite) is less than 10 and even
    if (availTours < TEN && availTours % TWO == ZERO) {
        segmentSize = availTours / TWO;
    } else if (availTours < TEN && availTours % TWO != ZERO) {
        segmentSize = (availTours + TEN) / TWO;
    } else if (availTours == THREE) {
        segmentSize = TWO;
    } else if (availTours == TWO) {
        segmentSize = ONE;
    } else if (availTours == ONE) {
        return;
    }

    // Populate parent1
    for (size_t i = ZERO; i < segmentSize && popIndex + i < popSize; ++i) {
        parent1->addTour(population[popIndex]);
        popIndex++;
        numTours--;
    }

    // Update segmentSize for parent2
    if (availTours < TEN && (segmentSize % TWO) == ZERO) {
        segmentSize = popSize - popIndex;
    } else if (availTours < TEN && segmentSize % TWO != ZERO) {
        segmentSize = popSize - popIndex;
    } else if (segmentSize == TWO && availTours == THREE) {
        segmentSize = ONE;
    }


    for (size_t i = ZERO; i < segmentSize; ++i) {
        parent2->addTour(population[popIndex]);
        popIndex++;
        numTours--;
    }
    //PRINTER for numTours Segment
//    cout << "remaining numTours after each 2 segment allocation" << endl;
//    cout << numTours << endl;


    // Find elites from both parents
    shared_ptr<Tour> elite1 = parent1->findElite();
    shared_ptr<Tour> elite2 = parent2->findElite();
    elite1->calcFitness();

    if (!elite1 || !elite2) {
        // Handle the case where one of the elites is null
        return;
    }
    elite2->calcFitness();

    //PRINTER FOR PARENT 1
//    cout << "set1 :" << endl;
//    cout << *parent1<< endl;

    //PRINTER FOR PARENT 2
//    cout << "set2 :" << endl;
//    cout << *parent2<< endl;

//     Merge parents' elites and add to child
    child->addTour(mergeParents(elite1, elite2));

    // Recursion termination condition
    if (popIndex >= popSize) {
        return;
    }

    // Recursive call
    eliteChildMaker(child, inputPop, popIndex);
}


shared_ptr<Tour> GeneticAlgo::mergeParents(shared_ptr<Tour> &parent1, const shared_ptr<Tour> &parent2) {

    auto child = make_shared<Tour>();
    unordered_set<string> addedCities;
    size_t randoSizeParent1 = randomInt(ZERO, parent1->getTour().size());

    // Add cities from parent1 up to the random size
    for (size_t i = ZERO; i < randoSizeParent1; ++i) {
        auto city = parent1->getTour()[i];
        child->addCity(city);
        addedCities.insert(city->getName());
    }

    // Add non-repeating cities from parent2
    for (const auto &city: parent2->getTour()) {
        if (addedCities.find(city->getName()) == addedCities.end()) {
            child->addCity(city);
            addedCities.insert(city->getName());
        }
    }
    child->calcFitness();

    //PRINTER FOR NEW CHILDREN
//    cout << "New child tour" << endl;
//    cout << *child << endl;
    return child;
}

int GeneticAlgo::randomInt(int min, int max) {
    RAND;
    uniform_int_distribution<> dist(min, max - ONE);
    return dist(gen);
}

void GeneticAlgo::tryMutate(const shared_ptr<Population> &inputPop) {
    const vector<shared_ptr<Tour>> &population = inputPop->getPopulation();

    for (size_t i = ONE; i < population.size(); ++i) {
        population[i]->mutateTour();
        population[i]->calcFitness();
    }
}



void GeneticAlgo::calculateImprovementRatio(const shared_ptr<Population> &newPop) {
    // Calculate the fitness of the new elite
    double newEliteFitness = newPop->findElite()->getFitness();

    // Calculate the improvement ratio
    improvedBY = originalEliteDistance / newEliteFitness;
}

void GeneticAlgo::evaluate(const shared_ptr<Population> &newPop, size_t iteration) {
    shared_ptr<Tour> newElite = newPop->findElite();
    double newEliteFitness = newElite->getFitness();

    cout << "Iteration " << iteration << ":\n";

    if (newEliteFitness < base_distance) {
        cout << "******************************NEW ELITE FOUND******************************" << endl;
        cout << "Distance: " << newEliteFitness << endl;
        calculateImprovementRatio(newPop);
        base_distance = newEliteFitness;
        cout << "Improvement over base: " << improvedBY << endl;
    } else {
        cout << "Elite's distance: " << base_distance << endl;
        cout << "Best Non Elite distance: " << newPop->getBestNonElite()->getFitness() << endl;
        cout << "Improvement over base: " << improvedBY << endl;
    }
    cout << "\n";
}

void GeneticAlgo::generateReport() {
    cout << "--- FINISHED ALGORITHM ---" << endl;

    // Total iterations
    cout << "Total iterations: " << --outputIterations << endl;

    // Original elite
    cout << "Original elite:" << endl;
    cout << "Distance: " << originalEliteDistance << endl;
    cout << *originalElite->getElite()<< endl;

    // Best elite
    cout << "\nBest elite:\n" << *base_pop->getElite()<< endl;
    cout << "Distance: " << base_pop->getElite()->getFitness() <<endl;


    // Improvement factor
    cout <<improvementFactor <<": Improvement factor GOAL of Reached!! "<< endl;
    cout << "Improvement factor : "<< improvedBY << endl;
    //garbage collection
    base_pop.reset();
    originalElite.reset();

}
GeneticAlgo* GeneticAlgo::instance = nullptr;

GeneticAlgo* GeneticAlgo::getInstance() {
    if (instance == nullptr) {
        instance = new GeneticAlgo();
    }
    return instance;
}



#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <iosfwd>
#include <sstream>
#include "animal.hpp"

using namespace std;
#pragma  once


class Canine: public Animal{

public:
    /**
 * Summary: Default constructor for Canine.
 * PRE: None.
 * POST: Initializes a Canine object with default values.
 */
    Canine(): Animal(getAge(), getId(), getAlive(), getLocation(*this)) {  }
/**
 * Summary: Constructor for Canine with parameters.
 * PRE: The provided values for age, ID, isAlive, and location must be valid.
 * POST: Initializes a Canine object with the specified values.
 */
   Canine(int age, long ID, bool isAlive, tuple<double, double, double> location) : Animal(age, ID, isAlive, location){
        this->setName("canine");
        cout<<"canine constructor"<<endl;
    }


    /**
   * Summary: Copy constructor for Canine.
   * PRE: The provided Canine object must be valid.
   * POST: Initializes a Canine object by copying another Canine object.
   */
    Canine(const Canine &other);

    /**
   * Summary: Virtual Destructor for Canine.
   * PRE: None.
   * POST: Destroys a Canine object.
   */
    ~Canine() override;

/**
 * Summary: Virtual function to simulate a Canine sleeping.
 * PRE: None.
 * POST: Prints a message indicating that the Canine is sleeping.
 */
    void sleep() override;

/**
 * Summary: Virtual function to simulate a Canine eating.
 * PRE: None.
 * POST: Prints a message indicating that the Canine is eating.
 */
    void eat()override;

/**
 * Summary: Hunt method for Canine.
 * PRE: The provided animalPtr must be a valid pointer to an Animal object.
 * POST: If the Canine and the other animal are in the same position, sets the other animal's alive status to false.
 */
    void hunt(Animal* animalPtr);
};


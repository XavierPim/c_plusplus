#include <iostream>
#include <tuple>
#include <sstream>

using namespace std;

#pragma once

class Animal {

private:
    int age;
    long ID;
    bool isAlive;
    tuple<double, double, double> location;
    string className;
public:

    /**
  * Summary: Default constructor for the Animal class.
  * PRE: None.
  * POST: Creates an Animal object with default values.
  */
    Animal() : age(0), ID(0), isAlive(true), location(make_tuple(0.0, 0.0, 0.0)) {}
    /**
 * Summary: Constructor with parameters for the Animal class.
 * PRE: Parameters age, ID, and location must be valid.
 * POST: Creates an Animal object with specified values.
 */
    Animal(int age, long ID, bool isAlive, tuple<double, double, double> location)
            : age(age), ID(ID), isAlive(isAlive), location(location){
        this->setName("animal");
       cout<<  "animal constructor" <<endl;
    }

    /**
  * Summary: Copy constructor for the Animal class.
  * PRE: The provided Animal object must exist.
  * POST: Creates a copy of the given Animal object.
  */
    Animal(const Animal& other);

    /**
   * Summary: Virtual function for moving the Animal.
   * PRE: Parameters move_x, move_y, and fly_z define the movement offsets.
   * POST: Updates the Animal's location based on the movement offsets.
   */
    virtual tuple<double, double, double>* move(double move_x, double move_y, double fly_z);

    /**
  * Summary: Virtual destructor for the Animal class.
  * PRE: None.
  * POST: Destroys the Animal object.
  */
    virtual ~Animal();

    /**
  * Summary: Virtual function for simulating sleep behavior.
  * PRE: None.
  * POST: Outputs a message indicating that the Animal is sleeping.
  */
    virtual void sleep();

    /**
   * Summary: Virtual function for simulating eating behavior.
   * PRE: None.
   * POST: Outputs a message indicating that the Animal is eating.
   */
    virtual void eat();

    /**
  * Summary: Sets the alive status of the Animal.
  * PRE: The provided boolean value must be valid.
  * POST: Updates the alive status of the Animal.
  */
    void setAlive(bool);
/**
 * Summary: member function to get the location of an Animal.
 * PRE: The provided Animal object must exist.
 * POST: Returns the location tuple of the Animal.
 */
    tuple<double, double, double> getLocation(const Animal&);

/**
 * Summary: Friend function to overload the insertion operator (<<) for Animal objects.
 * PRE: None.
 * POST: Outputs information about the Animal to the provided ostream.
 */
    friend ostream& operator<<(ostream& output, const Animal& animal);

/**
 * Summary: Getter for the age of the Animal.
 * PRE: None.
 * POST: Returns the age of the Animal.
 */
    int getAge() const;
/**
 * Summary: Getter for the ID of the Animal.
 * PRE: None.
 * POST: Returns the ID of the Animal.
 */
    long getId() const;

/**
 * Summary: Getter for the alive status of the Animal.
 * PRE: None.
 * POST: Returns the alive status of the Animal.
 */
    bool getAlive() const;
    /**
    * Summary: Getter for the name (class name) of the Animal.
    * PRE: None.
           * POST: Returns the name (class name) of the Animal.
    */
    const string &getName() const;
/**
 * Summary: Setter for the name (class name) of the Animal.
 * PRE: The provided class name must be valid.
 * POST: Updates the name (class name) of the Animal.
 */
    void setName(const string &className);
};





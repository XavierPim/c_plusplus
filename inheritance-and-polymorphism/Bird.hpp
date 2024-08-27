#include <cstdio>
#include <cstdlib>
#include <tuple>
#include "animal.hpp"

using namespace std;
#pragma  once

class Bird : public Animal {
public:

    /**
  * Summary: Default constructor for Bird.
  * PRE: None.
  * POST: Initializes a Bird object with default values.
  */
    Bird() : Animal(getAge(), getId(), getAlive(), Animal::getLocation(*this)) {}

    /**
   * Summary: Constructor for Bird with parameters.
   * PRE: The provided values for age, ID, isAlive, and location must be valid.
   * POST: Initializes a Bird object with the specified values.
   */
    Bird(int age, long ID, bool isAlive, tuple<double, double, double> location)
            : Animal(age, ID, isAlive, location) {
        this->setName("bird");
        cout<<"bird constructor"<<endl;
    }

    /**
   * Summary: Copy constructor for Bird.
   * PRE: The provided Bird object must be valid.
   * POST: Initializes a Bird object by copying another Bird object.
   */
    Bird(const Bird& other);

    /**
    * Summary: Destructor for Bird.
    * PRE: None.
    * POST: Destroys a Bird object.
    */
    ~Bird() override;

    /**
  * Summary: Virtual function to simulate a Bird eating.
  * PRE: None.
  * POST: Prints a message indicating that the Bird is eating.
  */
    void eat() override;

    /**
   * Summary: Virtual function to simulate a Bird sleeping.
   * PRE: None.
   * POST: Prints a message indicating that the Bird is sleeping.
   */
    void sleep() override;

};
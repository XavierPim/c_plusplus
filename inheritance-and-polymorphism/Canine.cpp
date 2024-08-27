#include "Canine.hpp"
#include "animal.hpp"
#include <iostream>

using namespace std;




void Canine::sleep() {
    cout << "Canine is sleeping" << endl;
}

void Canine::eat() {
    cout << "Canine is eating worms" << endl;
}

Canine::~Canine() {
    cout << "Canine is destroyed\n";
}

void Canine::hunt(Animal *animalPtr) {
    tuple<double, double, double> animalLocation = Animal::getLocation(*animalPtr);
    tuple<double, double, double> canineLocation = getLocation(*this);
    bool isWithinDistance = true;  // Assume initially that they are within distance

    // Check each dimension (x, y, z)
    for (int i = 0; i < 3; ++i) {
        double diff = get<0>(canineLocation) - get<0>(animalLocation);

        // Check if the difference is not within the range [-1, 1]
        if (diff < -1.0 || diff > 1.0) {
            isWithinDistance = false;
            break;
        }
    }
    if (isWithinDistance) {
        animalPtr->setAlive(false);
        cout<< this->getName() <<" " << this->getId() <<  " successfully hunted " << animalPtr->getName()<< endl;
    }
}





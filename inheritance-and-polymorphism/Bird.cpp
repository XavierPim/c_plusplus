#include "Bird.hpp"
#include "animal.hpp"
#include <iostream>

Bird::Bird(const Bird& other) : Animal(other) {}

// bird eat
void Bird::eat() {
    cout<< "bird is eating eggs"<<endl;
}
//bird destructor
Bird::~Bird(){
    cout<< "bird is destroyed"<< endl;
}

//bird sleep
void Bird::sleep() {
    cout << "bird is sleeping" << endl;
}







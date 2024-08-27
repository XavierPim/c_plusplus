#include "animal.hpp"
#include <iostream>
#include <iomanip>

using namespace std;


void Animal::sleep() {
    cout << "Animal is sleeping through lecture" << endl;
}

void Animal::eat() {
    cout << "Animal is eating people" << endl;
}

void Animal::setAlive(bool isIt) {
    isAlive = isIt;
}

Animal::Animal(const Animal &other) {
    age = other.age;
    ID = other.ID;
    isAlive = other.isAlive;
    location = other.location;
}

tuple<double, double, double> *Animal::move(double move_x, double move_y, double fly_z) {
    if( move_x >= 0 &&  move_y >= 0 && fly_z >=0){
        get<0>(location) = move_x;
        get<1>(location) = move_y;
        get<2>(location) = fly_z;
        cout<< this->getName()<< " " << this->getId() <<
        " moves to (" <<
        get<0>(location)<< ", "
       << get<1>(location)<< ", "
       << get<2>(location)<< ")"
        <<    endl;
        return &location;
    } else{
        cout<< "please enter points above -1"<<endl;
    }

}

Animal::~Animal() {
    cout << "animal is destroyed\n";
}

ostream &operator<<(ostream &output, const Animal &animal) {
    output << animal.getName() <<":[age=" << animal.age << ", id=" << animal.ID << ", alive=" << animal.isAlive;
    output << ", location=(" << get<0>(animal.location)<< fixed << setprecision(0) << ", " << get<1>(animal.location) << ", "
           << get<2>(animal.location) << ")]";
    return output;
}


tuple<double, double, double> Animal::getLocation(const Animal& animal) {
    return animal.location;
}

    int Animal::getAge() const {
        return age;
    }



    long Animal::getId() const {
        return ID;
    }


    bool Animal::getAlive() const {
        return isAlive;
    }

const string &Animal::getName() const {
    return className;
}

void Animal::setName(const string &name) {
    Animal::className = name;
}








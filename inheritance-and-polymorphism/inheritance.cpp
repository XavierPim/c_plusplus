//A00697839
//Xavier Pimentel

#include "Bird.hpp"
#include "Canine.hpp"
#include "animal.hpp"
#include <iostream>

using namespace std;

int main() {
    Animal* myAnimal = new Animal(10, 0, true, make_tuple(2.0, 8.0, 0.0));
    Bird* myBird = new Bird(15, 1, true, make_tuple(6.0, 3.0, 7.0));
    Canine* myCanine = new Canine(10, 2, true, make_tuple(8.0, 1.0, 0.0));
    cout << "---Create All animals---\n";
    cout << *myAnimal << endl;
    cout << *myBird << endl;
    cout << *myCanine << endl;

    cout << "\n---Make all animals move---\n";
    myAnimal->move(1.0, 1.0, 0.0);
    myBird->move(1.0, 2.0, 0.0);
    myCanine->move(1.0, 2.0, 0.0);

    cout << "\n---Make all animals sleep---\n";
    myAnimal->sleep();
    myBird->sleep();
    myCanine->sleep();


    cout << "\n---Make all animals eat---\n";
    myAnimal->eat();
    myBird->eat();
    myCanine->eat();

    cout << "\n---Make canine hunt bird---\n";
    myCanine->hunt(myBird);

    cout << "\n---Print all animals at end---\n";
    cout << *myAnimal << endl;
    cout << *myBird << endl;
    cout << *myCanine << endl;


    cout << "\n---Delete dynamic memory---\n";
    delete myAnimal;
    delete myBird;
    delete myCanine;
    return 0;
}
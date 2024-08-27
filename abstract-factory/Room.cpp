#include "Room.hpp"

void FairyRoom::addWall(Wall * wall) {
    walls.push_back(wall);
}

void FairyRoom::addDoor(Door *door) {
this->door = door;
}

void FairyRoom::printRoom(int id) {
    cout << "fairy Room "<<id<<" This room has fairies in it" << endl;
}

void DystopianRoom::addWall(Wall *wall) {
    walls.push_back(wall);
}

void DystopianRoom::addDoor(Door *door) {
this->door = door;
}

void DystopianRoom::printRoom(int id) {
    cout << "Dystopian Room "<< id<<" This room is full of despair" << endl;
}

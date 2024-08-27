#pragma once

#include <cstdlib>
#include <cstdio>
#include "Room.hpp"

class Room;

class Door {
public:
    virtual void addRoomA(Room *A) = 0;

    virtual void addRoomB(Room *B) = 0;

/*
 * Summary: Virtual destructor for Door class.
 * PRE: None.
 * POST: The Door object is destructed.
 * Return: None.
 */
    virtual ~Door() = default;

/*
 * Summary: Virtual function to print information about the door.
 * PRE: None.
 * POST: Information about the door is printed to the console.
 * Return: None.
 */
    virtual void printDoor(int id) = 0;
};

class DystopianDoor : public Door {
public:
    DystopianRoom *A;
    DystopianRoom *B;

    /*
     * Summary: Implementation of the virtual function to add a room to a dystopian door.
     * PRE: 'A' and 'B' are valid pointers to Room objects.
     * POST: 'A' is added as room A, 'B' is added as room B of the dystopian door.
     * Return: None.
     */
    void addRoomA(Room *A) override;
    /*
     * Summary: Implementation of the virtual function to add a room to a dystopian door.
     * PRE: 'A' and 'B' are valid pointers to Room objects.
     * POST: 'A' is added as room A, 'B' is added as room B of the dystopian door.
     * Return: None.
     */
    void addRoomB(Room *B) override;

    ~DystopianDoor() override {};
    /*
      * Summary: Implementation of the virtual function to print information about the dystopian door.
      * PRE: None.
      * POST: Information about the dystopian door is printed to the console.
      * Return: None.
      */
    void printDoor(int id) override;
};

class FairyDoor : public Door {
public:
    FairyRoom *A;
    FairyRoom *B;
    /*
     * Summary: Implementation of the virtual function to add a room to a fairy door.
     * PRE: 'A' and 'B' are valid pointers to Room objects.
     * POST: 'A' is added as room A, 'B' is added as room B of the fairy door.
     * Return: None.
     */
    void addRoomA(Room *A) override;
    /*
      * Summary: Implementation of the virtual function to add a room to a fairy door.
      * PRE: 'A' and 'B' are valid pointers to Room objects.
      * POST: 'A' is added as room A, 'B' is added as room B of the fairy door.
      * Return: None.
      */
    void addRoomB(Room *B) override;

    ~FairyDoor() override {};

    /*
     * Summary: Implementation of the virtual function to print information about the fairy door.
     * PRE: None.
     * POST: Information about the fairy door is printed to the console.
     * Return: None.
     */
    void printDoor(int id) override;
};

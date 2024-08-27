#pragma once

#include <cstdlib>
#include <vector>
#include <cstdio>
#include "Wall.hpp"
#include "Room.hpp"
#include "Door.hpp"

using namespace std;


class Maze {
public:
    vector<Room *> rooms;
    /*
   * Summary: Virtual function to add a room to the maze.
   * PRE: 'room' is a valid pointer to a Room object.
   * POST: 'room' is added to the maze's rooms vector.
   * Return: None.
   */
    virtual void addRoom(Room *room) = 0;
    virtual ~Maze()=default;
};


class DystopianMaze : public Maze {
public:
    /*
    * Summary: Implementation of the virtual function to add a room to a dystopian maze.
    * PRE: 'room' is a valid pointer to a Room object.
    * POST: 'room' is added to the dystopian maze's rooms vector.
    * Return: None.
    */
    void addRoom(Room *room) override;
};


class FairyMaze : public Maze {
public:
    /*
   * Summary: Implementation of the virtual function to add a room to a fairy maze.
   * PRE: 'room' is a valid pointer to a Room object.
   * POST: 'room' is added to the fairy maze's rooms vector.
   * Return: None.
   */
    void addRoom(Room *room) override;
};

#pragma once

#include <cstdlib>
#include <cstdio>

#include "Maze.hpp"

using namespace std;

class Maze_Factory {
public:
    enum{
        ZERO = 0,
        ONE = 1,
        FOUR = 4,
    };
    /*
  * Summary: Virtual function to create a maze.
  * PRE: None.
  * POST: A new Maze object is created.
  * Return: A pointer to the newly created Maze object.
  */
    virtual Maze *make_maze() = 0;

    /*
 * Summary: Virtual function to create a room.
 * PRE: None.
 * POST: A new Room object is created.
 * Return: A pointer to the newly created Room object.
 */
    virtual Room *make_room() = 0;

    /*
   * Summary: Virtual function to create a wall.
   * PRE: None.
   * POST: A new Wall object is created.
   * Return: A pointer to the newly created Wall object.
   */
    virtual Wall *make_wall() = 0;

    /*
 * Summary: Virtual function to create a door connecting two rooms.
 * PRE: 'A' and 'B' are valid pointers to Room objects.
 * POST: A new Door object is created connecting rooms 'A' and 'B'.
 * Return: A pointer to the newly created Door object.
 */
    virtual Door *make_door(Room *A, Room *B) = 0;

    /*
 * Summary: Virtual function to clear all pointers created by the factory.
 * PRE: None.
 * POST: All dynamically allocated objects created by the factory are deleted.
 * Return: None.
 */
    static void clearMaze(Maze *maze);

    virtual ~Maze_Factory()= default;
};

class FairyFactory : public Maze_Factory {
public:
    Maze *make_maze() override;

    Room *make_room() override;

    Wall *make_wall() override;

    Door *make_door(Room *A, Room *B) override;

    void printMaze(FairyMaze *maze);
};


class DystopianFactory : public Maze_Factory {
public:
    Maze *make_maze() override;

    Room *make_room() override;

    Wall *make_wall() override;

    Door *make_door(Room *A, Room *B) override;

    void printMaze(DystopianMaze *maze);
};



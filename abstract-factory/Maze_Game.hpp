#pragma once
#include <cstdlib>
#include <cstdio>
#include "Maze_Factory.hpp"

class Maze_Game {
public:
    // Singleton instance getter
    static Maze_Game& getInstance() {
        static Maze_Game instance;  // This will be created only once
        return instance;
    }

    // Creates a maze using the given factory
    Maze* create_maze(Maze_Factory* newMaze);

    // Singleton logic: delete copy constructor and assignment operator
    Maze_Game(const Maze_Game&) = delete;
    Maze_Game& operator=(const Maze_Game&) = delete;

private:
    // Private constructor to prevent external instantiation
    Maze_Game() {}
};
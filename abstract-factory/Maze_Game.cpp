

#include "Maze_Game.hpp"

Maze *Maze_Game::create_maze(Maze_Factory *newMaze) {
    return newMaze->make_maze();
}

//Name:Roy (Xavier) Pimentel
//Student# :A00697839

#include <iostream>
#include "Maze_Factory.hpp"
#include "Maze_Game.hpp"

using namespace std;

int main() {
    //singleton call for Maze_game
    Maze_Game &game = Maze_Game::getInstance();
    Maze_Factory::clearMaze(game.create_maze(new FairyFactory()));
    Maze_Factory::clearMaze( game.create_maze(new DystopianFactory()));
    return 0;
}

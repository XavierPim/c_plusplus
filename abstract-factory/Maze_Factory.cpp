
#include "Maze_Factory.hpp"

Maze *FairyFactory::make_maze() {
    auto *newMaze = new FairyMaze();
    auto *left = dynamic_cast<FairyRoom *>(make_room());
    auto *right = dynamic_cast<FairyRoom *>(make_room());
    make_door(left, right);
    newMaze->addRoom(left);
    newMaze->addRoom(right);
    printMaze(newMaze);
    return newMaze;
}

Room *FairyFactory::make_room() {
    FairyRoom *newRoom;
    newRoom = new FairyRoom();
    for (int i = ZERO; i < FOUR; ++i) {
        newRoom->addWall(make_wall());
    }
    return newRoom;
}

Wall *FairyFactory::make_wall() {
    FairyWall *newWall;
    newWall = new FairyWall;
    return newWall;
}

Door *FairyFactory::make_door(Room *A, Room *B) {
    FairyDoor *newDoor = new FairyDoor();
    newDoor->addRoomA(A);
    newDoor->addRoomB(B);
    A->door = newDoor;
    B->door = newDoor;
    return newDoor;
}

void FairyFactory::printMaze(FairyMaze *maze) {
    cout << "\nA pretty, magical fairy maze" << endl;
    for (size_t id = ZERO; id < maze->rooms.size(); ++id) {
        maze->rooms.at(id)->printRoom(id);
    }
    if (!maze->rooms.empty() && maze->rooms.at(ZERO)->door != nullptr) {
        maze->rooms.at(ZERO)->door->printDoor(ZERO);
    }
    for (Room *room: maze->rooms) {
        for (Wall *wall: room->walls) {
            wall->printWall();
        }
    }
}

Maze *DystopianFactory::make_maze() {
    auto *newMaze = new DystopianMaze();
    auto *left = dynamic_cast<DystopianRoom *>(make_room());
    auto *right = dynamic_cast<DystopianRoom *>(make_room());
    make_door(left, right);
    newMaze->addRoom(left);
    newMaze->addRoom(right);
    printMaze(newMaze);
    return newMaze;
}

Room *DystopianFactory::make_room() {
    DystopianRoom *newRoom;
    newRoom = new DystopianRoom();
    for (int i = ZERO; i < FOUR; ++i) {
        newRoom->addWall(make_wall());
    }
    return newRoom;
}

Wall *DystopianFactory::make_wall() {
    DystopianWall *newWall;
    newWall = new DystopianWall;
    return newWall;
}

Door *DystopianFactory::make_door(Room *A, Room *B) {
    DystopianDoor *newDoor = new DystopianDoor();
    newDoor->addRoomA(A);
    newDoor->addRoomB(B);
    A->door = newDoor;
    B->door = newDoor;
    return newDoor;
}

void DystopianFactory::printMaze(DystopianMaze *maze) {
    cout << "\nA dark and dystopian maze" << endl;
    for (size_t id = ZERO; id < maze->rooms.size(); ++id) {
        maze->rooms.at(id)->printRoom(id);
    }
    if (!maze->rooms.empty() && maze->rooms.at(ZERO)->door != nullptr) {
        maze->rooms.at(ZERO)->door->printDoor(ZERO);
    }
    for (Room *room: maze->rooms) {
        for (Wall *wall: room->walls) {
            wall->printWall();
        }
    }
}


void Maze_Factory::clearMaze(Maze *maze) {
    // Clear the maze's rooms and set the pointer to nullptr
    maze->rooms.at(ZERO)->door = nullptr;
    maze->rooms.at(ONE)->door = nullptr;
    for (Room *roomPtr: maze->rooms) {
        // Clear the room's walls and set the pointer to nullptr
        for (Wall *wallPtr: roomPtr->walls) {
            delete wallPtr;
        }
        roomPtr->walls.clear();
        delete roomPtr;
    }
    maze->rooms.clear();

    // Delete the maze and set the pointer to nullptr
    delete maze;
    maze = nullptr;
}

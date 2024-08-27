#pragma once
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "Wall.hpp"
class Door;

using namespace std;

class Room {
public:
    vector<Wall*> walls;
    Door* door;
    virtual ~Room()=default;
    virtual void addWall(Wall* wall )=0;
    virtual void addDoor(Door* door)=0;
    virtual void printRoom(int id)=0;
};

class FairyRoom:public Room{
public:
     void addWall(Wall* wall)override;
     void addDoor(Door* door)override;
    void printRoom(int id)override;
};

class DystopianRoom: public Room {
public:
    void addWall(Wall* wall)override;
     void addDoor(Door* door)override;
    void printRoom(int id)override;
};

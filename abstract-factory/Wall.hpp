#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class Wall {
public:
    /*
  * Summary: Virtual function to print information about the wall.
  * PRE: None.
  * POST: Wall information is printed to the console.
  * Return: None.
  */
    virtual void printWall() = 0;
    virtual ~Wall()=default;
};


class DystopianWall : public Wall {
public:
    /*
 * Summary: Implementation of the virtual function to print dystopian wall information.
 * PRE: None.
 * POST: Dystopian wall information is printed to the console.
 * Return: None.
 */
    void printWall() override;
};

class FairyWall : public Wall {
public:
    /*
  * Summary: Implementation of the virtual function to print fairy wall information.
  * PRE: None.
  * POST: Fairy wall information is printed to the console.
  * Return: None.
  */
    void printWall() override;
};
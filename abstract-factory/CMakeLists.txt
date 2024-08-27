cmake_minimum_required(VERSION 3.20)
project(CPlusplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(abstract-factory
        driver.cpp
        Maze_Factory.cpp
        Maze_Factory.hpp
        Maze.cpp
        Maze.hpp
        Room.cpp
        Room.hpp
        Door.cpp
        Door.hpp
        Wall.cpp
        Wall.hpp
        Maze_Game.cpp
        Maze_Game.hpp
)

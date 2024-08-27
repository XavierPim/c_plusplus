cmake_minimum_required(VERSION 3.20)
project(lab4template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(inheritance-and-polymorphism inheritance.cpp
        animal.cpp
        animal.hpp
        inheritance.cpp
        Bird.cpp
        Bird.hpp
        Canine.cpp
        Canine.hpp)

cmake_minimum_required(VERSION 3.20)
project(CPlusPlus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(genetic-algo-TSP main.cpp
        City.cpp
        City.hpp
        Population.cpp
        Population.hpp
        Tour.cpp
        Tour.hpp
        GeneticAlgo.cpp
        GeneticAlgo.hpp
)

cmake_minimum_required(VERSION 3.20)
project(google-search-ranking)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(google-search-ranking main.cpp
        matrix.cpp
        matrix.hpp
        MakrovProcess.cpp
        MakrovProcess.hpp
        FileReader.hpp
        FileReader.cpp
)

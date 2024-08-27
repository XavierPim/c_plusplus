cmake_minimum_required(VERSION 3.20)
project(lab4template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(library-generator main.cpp book.hpp library.cpp library.hpp
        Item.cpp
        Item.hpp
        Catalog.cpp
        Catalog.hpp
        ItemGenerator.cpp
        ItemGenerator.hpp
        DVD.hpp
        Journal.hpp)

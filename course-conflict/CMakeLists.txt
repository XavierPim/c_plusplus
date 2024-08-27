cmake_minimum_required(VERSION 3.20)
project(course-conflict)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(course-conflict main.cpp Course.hpp Course.cpp
)

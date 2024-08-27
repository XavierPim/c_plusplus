cmake_minimum_required(VERSION 3.20)
project(rpn_calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(rpn_calculator main.cpp
        abstract_operation.hpp
        addition_operation.hpp
        subtraction_operation.hpp
        division_operation.hpp
        multiplication_operation.hpp
        operation.hpp
        rpn_calculator.hpp
        rpn_calculator.cpp
)

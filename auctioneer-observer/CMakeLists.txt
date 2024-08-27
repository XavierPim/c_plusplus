cmake_minimum_required(VERSION 3.20)
project(CPlusPlus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(auctioneer-observer main.cpp auctioneer.cpp auctioneer.hpp auction.cpp auction.hpp bidder.cpp bidder.hpp)

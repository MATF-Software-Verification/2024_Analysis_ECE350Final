cmake_minimum_required(VERSION 3.10)

project(Durak)

set(CMAKE_CXX_STANDARD 14)

# Dodaj src folder kao direktorijum sa izvorima
add_executable(Durak src/main.cpp src/Card.cpp src/Deck.cpp)



cmake_minimum_required(VERSION 3.6)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Card.cpp Card.h d_node.h deck.cpp deck.h d_random.h)
add_executable(Project2 ${SOURCE_FILES})
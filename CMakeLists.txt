cmake_minimum_required(VERSION 3.14)
project(Sequence_producer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sequence_producer main.cpp global.cpp global.h primer.cpp primer.h)
cmake_minimum_required(VERSION 3.24)
project(dynamic2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
        DataStructures/Freighbor.cpp
        DataStructures/Freighbor.h
        DataStructures/Graph.cpp
        DataStructures/Graph.h
        DataStructures/Node.cpp
        DataStructures/Node.h
        main.cpp
        Matching.cpp Matching.h Logger.cpp Logger.h)

add_executable(dynamic2 ${SOURCE_FILES})

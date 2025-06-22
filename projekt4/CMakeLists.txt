cmake_minimum_required(VERSION 3.31)
project(TechInf1)

set(CMAKE_CXX_STANDARD 14)

include_directories(projekt4)

add_executable(TechInf1
        projekt4/arrayoperation.cpp
        projekt4/arrayoperation.h
        projekt4/main.cpp)

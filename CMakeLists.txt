cmake_minimum_required(VERSION 3.29)
project(chessgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(chessgame main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

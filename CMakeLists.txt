cmake_minimum_required(VERSION 3.0)

project(matmul)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matmul src/matmul.cpp)
cmake_minimum_required(VERSION 3.22)
project(CppDll)

set(CMAKE_CXX_STANDARD 23)

add_library(CppDll SHARED library.cpp)

cmake_minimum_required(VERSION 3.16)
project(exo5)

set(CMAKE_CXX_STANDARD 14)

add_executable(exo5 main.cpp analyseur/LexicalAnalyzer.cpp analyseur/LexicalAnalyzer.h)

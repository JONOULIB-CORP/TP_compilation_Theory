cmake_minimum_required(VERSION 3.16)
project(exo4)

set(CMAKE_CXX_STANDARD 14)

add_executable(exo4 main.cpp analyseur/LexicalAnalyzer.cpp analyseur/LexicalAnalyzer.h)

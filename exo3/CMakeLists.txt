cmake_minimum_required(VERSION 3.16)
project(exo3)

set(CMAKE_CXX_STANDARD 14)

add_executable(exo3 main.cpp source/DFA.cpp header/DFA.h source/DFA_Generalisation.cpp header/DFA_Generalisation.h source/exo3-1.cpp header/exo3-1.h header/exo3-2.h source/exo3-2.cpp)

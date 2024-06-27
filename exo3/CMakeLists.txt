cmake_minimum_required(VERSION 3.16)
project(exo3)

set(CMAKE_CXX_STANDARD 14)

add_executable(exo3 main.c source/DFA.c header/DFA.h source/DFA_Generalisation.c header/DFA_Generalisation.h source/exo3_1.c header/exo3_1.h header/exo3_2.h source/exo3_2.c)

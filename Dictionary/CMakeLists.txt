cmake_minimum_required(VERSION 3.17)
project(Dictionary C)

set(CMAKE_C_STANDARD 99)

add_executable(Dictionary main.c Word/Word.c Word/Word.h Utils/Utils.c Utils/Utils.h)
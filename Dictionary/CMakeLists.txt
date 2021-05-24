cmake_minimum_required(VERSION 3.17)
project(Dictionary C)

set(CMAKE_C_STANDARD 99)

add_executable(Dictionary main.c Word/Word.c Word/Word.h Utils/Utils.c Utils/Utils.h Array/Array.c Array/Array.h LinkedList/LinkedList.c LinkedList/LinkedList.h BinarySearchTree/BinarySearchTree.c BinarySearchTree/BinarySearchTree.h Heap/Heap.c Heap/Heap.h HashTable/HashTable.c HashTable/HashTable.h Menu/Menu.c Menu/Menu.h)
cmake_minimum_required(VERSION 3.22)
project(Data)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data main.cpp LinkedList.cpp LinkedList.h DoublyLinkedList.cpp DoublyLinkedList.h Binary.cpp Binary.h BinarySearchTree.cpp BinarySearchTree.h UndirectedGraph.cpp UndirectedGraph.h AdjacencyMatrix.cpp AdjacencyMatrix.h AdjacencyList.cpp AdjacencyList.h BellmanFord.cpp BellmanFord.h)

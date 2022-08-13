//
// Created by adeog on 24/07/2022.
//

#ifndef DATA_ADJACENCYMATRIX_H
#define DATA_ADJACENCYMATRIX_H
#include <iostream>

using namespace std;

class AdjacencyMatrix {
private:
    int n;//this is the size like the width and height
    int **adjList;
public:
    AdjacencyMatrix(int n){
        this->n = n;
        adjList = new int*[n];
        for (int i = 0; i < n; ++i) {
            adjList[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                adjList[i][j] = 0;
            }
        }
    }

    //add a new edge to the graph
    void addEdge(int orig, int dest){
        if(orig > n || dest > n || orig < 1 || dest < 1){
            cout << "Trying to add an invalid edge" << endl;
            cout << "(" << orig << "," << dest << ")" << endl;
        }else{
            adjList[orig-1][dest -1] = 1;
        }
    }

    //remove an edge
    void removeEdge(int orig, int dest){
        if(orig > n || dest > n || orig < 1 || dest < 1){
            cout << "Trying to add an invalid edge" << endl;
            cout << "(" << orig << "," << dest << ")" << endl;
        }else{
            adjList[orig-1][dest -1] = 0;
        }
    }
    
    void Display(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};


#endif //DATA_ADJACENCYMATRIX_H

//
// Created by adeog on 24/07/2022.
//

#ifndef DATA_ADJACENCYLIST_H
#define DATA_ADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next= nullptr;
    }
};
//vertex A(1) -> {[B(2)], [C(3)] } - A is connected to B and C
//vertex B(2) -> {[A(1)], [D(4)] } - B is connected to A and D

class VertexList{//the list of vertexes this vertex is contected to  e.g. This would be A as A has its value (1) and its next (its connection) is B which also has its value (2)
public:
    Node* Head;
};

class Graph {
public:
    int v;//how many vertices/how many nodes
    VertexList *vl;//list of vertices - so this would a list/vector of all the vertex lists e.g. vl = {A,B,C,D};  vl[0] = A, vl[1] = B etc

    Graph(int n){
        v = n;
        //create a list for n vertexes
        vl = new VertexList[n];
        //assign the head to null
        for (int i = 0; i < n; ++i) {
            vl[i].Head = nullptr;
        }
    }
    void addEdge(int src, int dest){
        Node* n = new Node(dest);//Creates a new node with a value// node unknown with a value of 4
        n->next = vl[src].Head;//let the new node point at the node it is coming from // node unknown points to node C
        vl[src].Head = n; // Node unknown = node C with a value of 4
        n = new Node(src);//node unknown =
        n->next = vl[dest].Head;
        vl[dest].Head = n;
    }

    void Print(){
        for (int i = 0; i < v; ++i) {
            Node* temp = vl[i].Head;
            cout << "\n Adjacency List of vertex " << i << endl;
            while(temp){
                cout << " -> " << temp->data;
                temp = temp->next;
            }
        }
    }

};


class Graph2{
private:
    int v;// number of vertices
    vector<int> *adj;

    void TopologicalSort(int v, bool visited[], stack<int> &Stack){
        visited[v] = true; //mark current node as visited
        vector<int>::iterator i;
        //Recur for all the vertices adjacent to this vertex.
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                TopologicalSort(*i, visited, Stack);
        Stack.push(v);
    }

public:
    Graph2(int v){
        this->v = v;
        adj = new vector<int>[v];
    }

    void AddEdge(int v, int w){
        adj[v].push_back(w);
    }

    void DFS(int s){
        vector<bool> visited(v, false);
        stack<int> DFSStack;
        DFSStack.push(s);
        while(!DFSStack.empty()) {
            //pop a vertex from stack and print it
            s = DFSStack.top();
            DFSStack.pop();

            //stack may contain the same vertex twice. So we need to print the popped item only if it is not visited
            if (!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }
            // get all adjacent vertices of the popped vertex s. If an adjacent has not been visited, then push it to the stack
            for (auto i = adj[s].begin(); i < adj[s].end(); ++i) {
                if (!visited[*i]) {
                    DFSStack.push(*i);
                }
            }
        }
    }

    void BFS(int s){
        vector<bool> visited(v, false);

        queue<int> BFSQueue;
        visited[s] = true;
        BFSQueue.push(s);
        while(!BFSQueue.empty()){
            s = BFSQueue.front();
            cout << "Visited " << s << " ";
            BFSQueue.pop();
            for (auto i = adj[s].begin(); i < adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    BFSQueue.push(*i);
                }
            }
        }
    }

    void Topological(){
        stack<int> Stack;
        bool *visited = new bool[v];
        //Mark all the vertices which are not visited.
        for (int i = 0; i < v; i++)
            visited[i] = false;
        for (int i = 0; i < v; i++)
            if (visited[i] == false)
                //Call the function topologicalSort().
                TopologicalSort(i, visited, Stack);
        while (Stack.empty() == false) {
            cout << Stack.top() << " "; //print the element
            Stack.pop();
        }
    }


};

#endif //DATA_ADJACENCYLIST_H

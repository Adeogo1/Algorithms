
#include <iostream>
#include "LinkedList.h"
#include "Binary.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "BellmanFord.h"
using namespace std;

void LinkedListTest();
void BinaryTreeTest();
void AdjacencyMatrixTest();
void BinarySearchTest();
int BinarySearch(vector<int> arr, int l, int r, int search);
void AdjacencyListTest1();
void AdjacencyListTest2();
void BelmanFordTest();

int main() {

    cout << "Hello, World! why arent you working" << endl;
    //AdjacencyMatrixTest();
    //BinarySearchTest();
    //AdjacencyListTest1();
    //AdjacencyListTest2();
    BelmanFordTest();
}

void LinkedListTest() {
    LinkedList* L = new LinkedList(0);
    for (int i = 1; i < 4; ++i) {
        L->AddToTheEnd(i);
    }
    cout << L->Find(2)->data << endl;
    cout << L->Find(L->Size())->data << endl;

    L->PrintList();
    cout << endl;
    L->PrintReverseList();

    cout << L->Size() << endl;

}

void DoublyLinkedListTest(){

}

void BinaryTreeTest(){
    BinaryTree* Tree = new BinaryTree(1);
    Tree->MakeTree();
    //Tree->PreOrderTraversal();
    //cout << Tree->FindHeight()<< endl;
    //Tree->LevelOrderTraversal();

    vector<TreeNode*> DFS = Tree->DFS();
    for (TreeNode* node:DFS) {
        cout << node->data << " ";
    }
    cout << endl;

    vector<TreeNode*> DFS2 = Tree->RecursiveDFS();
    for (TreeNode* node:DFS2) {
        cout << node->data << " ";
    }
    cout << endl;

    vector<TreeNode*> BFS = Tree->BFS();
    for (TreeNode* node:BFS) {
        cout << node->data << " ";
    }
    cout << endl;
}

void AdjacencyMatrixTest(){
    AdjacencyMatrix* M = new AdjacencyMatrix(5);
    M->addEdge(2,5);
    M->addEdge(1,5);
    M->addEdge(5,1);
    M->addEdge(3,3);
    //M->removeEdge(1,5);

    M->Display();
}

void BinarySearchTest(){
    vector<int> arr{3,4,23,42,77,100};
    int x = 42;
    int result = BinarySearch(arr,0, arr.size()-1, x);
    if (result == -1){
        cout << "element not found" << endl;
    }else{
        cout << "element at " << result << endl;
    }
}

int BinarySearch(vector<int> arr, int l, int r, int search){
    if (r >= 1){
        int mid = (l + (r-1))/2;
        if (arr[mid] == search){ return mid; }
        if (arr[mid] > search){
            return BinarySearch(arr, l, mid -1, search);
        }else
        {
            return BinarySearch(arr,mid +1, r, search);
        }
    }
    return -1;
}

void AdjacencyListTest1(){
    Graph* G = new Graph(5);

    G->addEdge(0,1);
    G->addEdge(0,2);
    G->addEdge(2,3);
    G->addEdge(1,3);
    G->addEdge(1,4);
    G->addEdge(3,4);
    G->Print();
}

void AdjacencyListTest2(){
    Graph2* G = new Graph2(7);

    G->AddEdge(0,1);
    G->AddEdge(0,2);
    G->AddEdge(0,3);
    G->AddEdge(1,4);
    G->AddEdge(1,5);
    G->AddEdge(2,6);
    G->DFS(0);
    cout << endl;
    G->BFS(0);
    cout << endl;

    Graph2 g(6);
    g.AddEdge(4, 2);
    g.AddEdge(5, 1);
    g.AddEdge(4, 0);
    g.AddEdge(3, 1);
    g.AddEdge(1, 3);
    g.AddEdge(3, 2);

    cout << "Topological Sort of the given graph \n";
    g.Topological();
}

void BelmanFordTest(){
    BellmanFordEdgeList* B = new BellmanFordEdgeList(9);
    B->AddEdge(0,1,1);
    B->AddEdge(1,2,1);
    B->AddEdge(2,4,1);
    B->AddEdge(4,3,-3);
    B->AddEdge(3,2,1);
    B->AddEdge(1,5,4);
    B->AddEdge(1,6,4);
    B->AddEdge(5,6,5);
    B->AddEdge(6,7,4);
    B->AddEdge(5,7,3);

    vector<double> d = B->BelmanFord(0);
    for (int i = 0; i < 9; ++i) {
        printf("The cost to get from node %d to %d is %.2f\n",0,i,d[i]);

    }
}

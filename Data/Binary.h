//
// Created by adeog on 15/07/2022.
//

#ifndef DATA_BINARY_H
#define DATA_BINARY_H
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _data){
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* Root;

    BinaryTree(int _data){
        Root = new TreeNode(_data);
    }

    void MakeTree();

    void AddToLeftNode(TreeNode* n, int data);
    void AddToRightNode(TreeNode* n, int data);
    void InsertLeft(TreeNode* n, int data);
    void InsertRight(TreeNode* n, int data);

    void PreOrderTraversal();
    void InOrderTraversal();
    void PostOrderTraversal();
    void LevelOrderTraversal();
    int FindHeight();//number of edges in the longest path from root to leaf node
    vector<TreeNode*> DFS();
    vector<TreeNode*> RecursiveDFS();
    vector<TreeNode*> BFS();

private:
    void PreOrderTraversal(TreeNode* n);
    void InOrderTraversal(TreeNode* n);
    void PostOrderTraversal(TreeNode* n);
    void LevelOrderTraversal(TreeNode* n);
    void CurrentLevel(TreeNode* n);
    int FindHeight(TreeNode* n);
    void RecursiveDFS(TreeNode* n, vector<TreeNode*> &v);
};



#endif //DATA_BINARY_H

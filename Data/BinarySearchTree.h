//
// Created by adeog on 16/07/2022.
//

#ifndef DATA_BINARYSEARCHTREE_H
#define DATA_BINARYSEARCHTREE_H
#include <iostream>
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

class BinarySearchTree {
public:
    TreeNode* Root;
    BinarySearchTree(int data) {
        Root = new TreeNode(data);
    }
    void InsertNode(int data);
    TreeNode* Search(int data);

private:
    void InsertNode(TreeNode* t,int data);
    TreeNode* Search(TreeNode* t,int data);
};


#endif //DATA_BINARYSEARCHTREE_H

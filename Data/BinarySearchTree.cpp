//
// Created by adeog on 16/07/2022.
//

#include "BinarySearchTree.h"

void BinarySearchTree::InsertNode(int data){
    InsertNode(Root, data);
    //InsertNode2(Root, data);

}

void BinarySearchTree::InsertNode(TreeNode* t,int data){
    if (t == nullptr){
        TreeNode* newNode = new TreeNode(data);
        t = newNode;
        return;
    }
    if (data <= t->data){
        InsertNode(t->left, data);
    }else{
        InsertNode(t->right,data);
    }

}

TreeNode* BinarySearchTree::Search(int data) {
    return Search(Root, data);
}

TreeNode* BinarySearchTree::Search(TreeNode *t, int data) {
    if (t == nullptr)return nullptr;
    else if (t->data == data) return t;
    else if (t->data >= data)  return Search(t->left, data);
    else return Search(t->right, data);
}

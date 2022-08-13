//
// Created by adeog on 15/07/2022.
//

#include "Binary.h"

void BinaryTree::MakeTree(){
    AddToLeftNode(Root, 2);
    AddToRightNode(Root, 3);
    AddToLeftNode(Root->right, 6);
    AddToRightNode(Root->right, 7);

    AddToLeftNode(Root->left, 4);
    AddToRightNode(Root->left, 5);
}

void BinaryTree::AddToLeftNode(TreeNode* n, int data){
    if(n->left != nullptr){
        return;
    }
    n->left = new TreeNode(data);

}
void BinaryTree::AddToRightNode(TreeNode* n, int data){
    if(n->right != nullptr){
        return;
    }
    n->right = new TreeNode(data);
}

void BinaryTree::InsertLeft(TreeNode* n, int data){
    TreeNode* newNode = new TreeNode(data);
    newNode->left = n->left;
    n->left = newNode;
}

void BinaryTree::InsertRight(TreeNode* n, int data){
    TreeNode* newNode = new TreeNode(data);
    newNode->right = n->right;
    n->right = newNode;
}

void BinaryTree::PreOrderTraversal(){
    PreOrderTraversal(Root);
}
void BinaryTree::InOrderTraversal(){
    InOrderTraversal(Root);
}
void BinaryTree::PostOrderTraversal(){
    PostOrderTraversal(Root);
}

void BinaryTree::LevelOrderTraversal() {
    if (Root != nullptr){
        cout << Root->data << endl;
    }else{
        return;
    }
    LevelOrderTraversal(Root);
}

int BinaryTree::FindHeight() {
    return FindHeight(Root);
}

void BinaryTree::PreOrderTraversal(TreeNode* n){
    cout << n->data << endl;
    if (n->left != nullptr){
        PreOrderTraversal(n->left);
    }
    if (n->right != nullptr){
        PreOrderTraversal(n->right);
    }
}
void BinaryTree::InOrderTraversal(TreeNode* n){
    if (n->left != nullptr){
        InOrderTraversal(n->left);
    }
    cout << n->data << endl;
    if (n->right != nullptr){
        InOrderTraversal(n->right);
    }
}
void BinaryTree::PostOrderTraversal(TreeNode* n){
    if (n->left != nullptr){
        PostOrderTraversal(n->left);
    }
    if (n->right != nullptr){
        PostOrderTraversal(n->right);
    }
    cout << n->data << endl;
}

int BinaryTree::FindHeight(TreeNode* n){
    if (n == nullptr){
        return -1;//if you want number of edges the do -1 if you want number of nodes do 0
    }
    int height = max(FindHeight(n->left), FindHeight(n->right));
    return height+1;
}

void BinaryTree::LevelOrderTraversal(TreeNode* n) {

    if (n == nullptr)
        return;

    CurrentLevel(n);
    LevelOrderTraversal(n->left);
    LevelOrderTraversal(n->right);

}

void BinaryTree::CurrentLevel(TreeNode *n) {
    if (n->left != nullptr){
        cout << n->left->data << endl;
    }
    if (n->right != nullptr){
        cout << n->right->data << endl;
    }

}

vector<TreeNode *> BinaryTree::DFS() {
    if (Root == nullptr)
        return vector<TreeNode*>{Root};

    vector<TreeNode*> results;
    stack<TreeNode*> Nodes;
    Nodes.push(Root);
    while (Nodes.size() > 0){
        TreeNode* current = Nodes.top();
        Nodes.pop();
        results.push_back(current);

        //pushing the left first onto the stack it means that the
        // right child will be on top for the next iteration -
        // so basically to traverse the right side first

        if (current->right != nullptr){
            Nodes.push(current->right);
        }
        if (current->left != nullptr){
            Nodes.push(current->left);
        }
    }

    return results;
}

vector<TreeNode *> BinaryTree::RecursiveDFS() {
    if (Root == nullptr)
        return vector<TreeNode*>{Root};

    vector<TreeNode*> results;
RecursiveDFS(Root, results);
    return results;
}

void BinaryTree::RecursiveDFS(TreeNode* n, vector<TreeNode*> &v){
    v.push_back(n);
    if (n->left != nullptr){
        RecursiveDFS(n->left, v);
    }
    if (n->right != nullptr){
        RecursiveDFS(n->right, v);
    }
}

vector<TreeNode *> BinaryTree::BFS() {

    if (Root == nullptr)
        return vector<TreeNode*>{Root};

    vector<TreeNode*> results;
    queue<TreeNode*> Nodes;
    Nodes.push(Root);
    while (Nodes.size() > 0){
        TreeNode* current = Nodes.front();
        Nodes.pop();
        
        results.push_back(current);
        if (current->left != nullptr){
            Nodes.push(current->left);
        }
        if (current->right != nullptr){
            Nodes.push(current->right);
        }

    }

    return results;
}


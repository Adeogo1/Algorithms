//
// Created by adeog on 04/07/2022.
//

#ifndef DATA_LINKEDLIST_H
#define DATA_LINKEDLIST_H
#include <iostream>

using namespace std;


class node{
public:
    int data;
    node* next;
    node(int x){
        data = x;
        next = nullptr;
    }
};

class LinkedList{
public:
    node* head;

    LinkedList(int _data){
        head = new node(_data);
    }
    ~LinkedList();
    void AddToTheFront(int _data);
    void AddToTheEnd(int _data);
    void InsertAfter(node* n, node* nodeToInsert);
    void InsertAfter(int pos, int _data);
    node* Find(node* n);
    node* Find(int pos);
    void DeleteNode(node* n);
    node* GetLastNode();
    bool Contains(node* n);
    bool isEmpty();
    void PrintList();
    int Size();
    void PrintReverseList();
};


#endif //DATA_LINKEDLIST_H

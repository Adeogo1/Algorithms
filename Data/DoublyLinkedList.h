//
// Created by adeog on 15/07/2022.
//

#ifndef DATA_DOUBLYLINKEDLIST_H
#define DATA_DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int _data){
        data = _data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {

    Node* head;

    DoublyLinkedList(int _data){
        head = new Node(_data);
    }
    ~DoublyLinkedList();
    void AddToTheFront(int _data);
    void AddToTheEnd(int _data);
    void InsertAfter(Node* n, Node* nodeToInsert);
    void InsertAfter(int pos, int _data);
    Node* Find(Node* n);
    Node* Find(int pos);
    void DeleteNode(Node* n);
    Node* GetLastNode();
    bool Contains(Node* n);
    bool isEmpty();
    void PrintList();
    int Size();
    void PrintReverseList();

};


#endif //DATA_DOUBLYLINKEDLIST_H

//
// Created by adeog on 15/07/2022.
//

#include "DoublyLinkedList.h"

DoublyLinkedList::~DoublyLinkedList(){

}

void DoublyLinkedList::AddToTheFront(int _data){
    Node* newNode = new Node(_data);
    head->prev = newNode;
    newNode->next = head;
}
void DoublyLinkedList::AddToTheEnd(int _data){
    Node* newNode = new Node(_data);
    Node* tempNode = head;
    while (tempNode->next != nullptr){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->prev = tempNode;
}
void DoublyLinkedList::InsertAfter(Node* n, Node* nodeToInsert){
    if(!Contains(n)){
        return;
    }
    Node* tempNode = n->next;
    n->next = nodeToInsert;
    nodeToInsert->next = tempNode;
    nodeToInsert->prev = n;
    nodeToInsert->next->prev = nodeToInsert;
}
void DoublyLinkedList::InsertAfter(int pos, int _data){

}
Node* DoublyLinkedList::Find(Node* n){
    Node* tempNode = head;
    while (tempNode != nullptr) {
        if (tempNode == n)
            return tempNode;
        tempNode = tempNode->next;
    }
    return nullptr;
}
Node* DoublyLinkedList::Find(int pos){
    Node* tempNode = head;
    for (int i = 0; i < pos-1; ++i) {
        tempNode = tempNode->next;
    }
    return tempNode;
}
void DoublyLinkedList::DeleteNode(Node* n){

}
Node* DoublyLinkedList::GetLastNode(){
    Node* tempNode = head;
    while(tempNode->next != nullptr){
        tempNode = tempNode->next;
    }
    return tempNode;
}
bool DoublyLinkedList::Contains(Node* n){

}
bool DoublyLinkedList::isEmpty(){
    if (head == nullptr)
        return true;
    return false;
}

void DoublyLinkedList::PrintList(){
    Node* tempNode = head;
    while (tempNode != nullptr){
        cout << tempNode->data << "->";
        tempNode = tempNode->next;
    }
}
int DoublyLinkedList::Size(){
    Node* tempNode = head;
    int size = 0;
    while(tempNode != nullptr){
        size++;
        tempNode = tempNode->next;
    }
    return size;
}
void DoublyLinkedList::PrintReverseList(){
    Node* tempNode = head;
    for (int i = Size(); i >0 ; i--) {
        cout << Find(i)->data << "->";
    }
    cout << endl;
}
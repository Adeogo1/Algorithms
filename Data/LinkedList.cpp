//
// Created by adeog on 04/07/2022.
//

#include "LinkedList.h"
void LinkedList::AddToTheFront(int _data) {

    node* newNode = new node(_data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::AddToTheEnd(int _data) {
    node* newNode = new node(_data);
    if (head == nullptr) {
        head = newNode;
        newNode->next = nullptr;
    }
    else{
        node* n2 = GetLastNode();
        n2->next = newNode;
    }
}

void LinkedList::InsertAfter(node* n, node* nodeToInsert) {
    if (!Contains(n))
        return;
    node* tempNode = n->next;
    n->next = nodeToInsert;
    nodeToInsert->next = tempNode;
}

void LinkedList::InsertAfter(int pos, int _data){
    node* newNode = new node(_data);
    node* tempNode = head;
    for (int i = 0; i < pos  ; ++i) {
        tempNode = tempNode->next;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;

}

node *LinkedList::Find(node* n) {

    node* tempNode = head;
    while (tempNode != nullptr) {
        if (tempNode == n)
            return tempNode;
        tempNode = tempNode->next;
    }
    return nullptr;
}


node *LinkedList::Find(int pos) {

    node* tempNode = head;
    for (int i = 0; i < pos-1; ++i) {
        tempNode = tempNode->next;
    }
    return tempNode;
}
bool LinkedList::isEmpty() {
    if (head == nullptr)
        return true;
    return false;
}

void LinkedList::PrintList() {
    node* tempNode = head;
    while (tempNode != nullptr){
        cout << tempNode->data << "->";
        tempNode = tempNode->next;
    }
}
node *LinkedList::GetLastNode() {
    node* tempNode = head;
    while(tempNode->next != nullptr){
        tempNode = tempNode->next;
    }
    return tempNode;
}

void LinkedList::DeleteNode(node *n) {
    node* tempNode = head;
    if (n == tempNode){
        node* prevNode = tempNode;
        while (tempNode-> next != nullptr){
            prevNode = tempNode;
            tempNode = tempNode->next;
            delete prevNode;
            prevNode = nullptr;
        }
        return;
    }
    node* prevNode = tempNode;
    while (tempNode != n){
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = tempNode->next;
    delete tempNode;
    tempNode = nullptr;

}

bool LinkedList::Contains(node *n) {
    node* tempNode = head;
    while (tempNode != nullptr){
        if (tempNode == n){
            return true;
        }
        tempNode = tempNode->next;
    }
    return false;
}

LinkedList::~LinkedList() {
    DeleteNode(head);
}

int LinkedList::Size() {
    node* tempNode = head;
    int size = 0;
    while(tempNode != nullptr){
        size++;
        tempNode = tempNode->next;
    }
    return size;
}

void LinkedList::PrintReverseList() {
    node* tempNode = head;
    for (int i = Size(); i >0 ; i--) {
        cout << Find(i)->data << "->";
    }
    cout << endl;

}

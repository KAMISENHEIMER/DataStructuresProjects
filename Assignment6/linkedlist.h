/*********************
Name: Kaden Misenheimer
Assignment 6: Linked Lists
Purpose: This is the header file for the linkedlist.cpp file. It contains all method prototypes and attributes necessary for the Linked List.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "data.h"


class LinkedList {

public:

    //constructor
    LinkedList();

    //deconstructor
    ~LinkedList();

    //methods
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);   //defaults bool to false
    int getCount();
    bool clearList();
    bool exists(int);

private:

    void createNode(Node*, int, string*);
    void insertNode(char, int, string*, Node* = nullptr);    //defaults the location node to nullptr
    void insertFirstNode(Node*);
    void insertHeadNode(Node*);
    void insertMidNode(Node*, Node*);
    void insertTailNode(Node*, Node*);

    //one and only one attribute
    // points at first node in linked list
    Node *head;

};

#endif //LINKEDLIST_H
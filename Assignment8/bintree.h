/*********************
Name: Kaden Misenheimer
Assignment 8: Binary Search Tree
Purpose: This is the header file for bintree.cpp, it contains the prototypes and attributes for the Binary Search Tree ADT.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include "data.h"

class BinTree {

public:

    //constructor
    BinTree();

    //deconstructor
    ~BinTree();

    //public methods
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    //public methods with overloads
    void clear();
    bool addNode(int,const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:

    //overload methods
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    //private methods
    DataNode* minValueNode(DataNode*);

    //attributes
    DataNode *root;
    int count;

};

#endif /* BINTREE_BINTREE_H */


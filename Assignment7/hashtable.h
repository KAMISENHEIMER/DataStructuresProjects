/*********************
Name: Kaden Misenheimer
Assignment 7: Hash Tables
Purpose: This is the header file for the hashtable.cpp file. It contains all method prototypes and attributes necessary for the Hash Table.
**********************/


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "linkedlist.h"

#define HASHTABLESIZE 15

class HashTable {

public:

    //constructor
    HashTable();

    //deconstructor
    ~HashTable();

    //methods
    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:

    //methods
    int hash(int);

    //attributes
    int count;
    LinkedList **hashtable;

};

#endif //HASHTABLE_H
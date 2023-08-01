/*********************
Name: Kaden Misenheimer
Challenge 2: Hash Tables: Separate Chaining
Purpose: This is the header file for the hashtable.cpp file. It contains all method prototypes and attributes necessary for the Hash Table.
**********************/


#ifndef HASH_H
#define HASH_H

#include "string"
#include <iostream>

#define HASHTABLESIZE 15

struct Data {
    int id;
    std::string data;
};

struct Node {
    Data data;
    Node *next;
};

class Hash {

public:

    //constructor
    Hash();

    //deconstructor
    ~Hash();

    //methods
    bool addEntry(int, std::string*);
    bool removeEntry(int);
    bool getEntry(Data*, int);
    int count();
    void displayTable();


private:

    //methods
    int hash(int);

    //attributes
    int _count;
    Node **heads;

};

#endif //HASH_H
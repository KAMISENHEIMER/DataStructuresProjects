/*********************
Name: Kaden Misenheimer
Assignment 7: Hash Tables
Purpose: This file details the constructor, deconstructor, and all methods related to the hash table ADT
**********************/

#include "hashtable.h"

//constructor
HashTable::HashTable() {

    hashtable = new LinkedList *[HASHTABLESIZE];
    count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = new LinkedList();
    }

}

//deconstructor
HashTable::~HashTable() {

    for (int i = HASHTABLESIZE-1; i >= 0; i--) {
        delete hashtable[i];
    }

    delete[] hashtable;
}

//methods
bool HashTable::insertEntry(int id, string *info) {

    bool success = false;

    if (id >=0 && info->length() > 0) {
        //if data is valid, attempt to add it to the list that corresponds with its hash
        //technically this is the same if statement that the LinkedList uses, but as every class should be responsible for the data they pass, I feel the check here is reasonable.
        success = hashtable[hash(id)]->addNode(id, info);
    }

    //increases count if adding was successful
    if (success) {
        count++;
    }

    return success;
}

string HashTable::getData(int id) {

    Data returnData;
    string returnString = "Not found";
    //ensures id is positive, then gets the linked list to look in, then looks for id
    if (id>0 && hashtable[hash(id)]->getNode(id, &returnData)) {
        returnString = returnData.data;
    }

    return returnString;
}

bool HashTable::removeEntry(int id) {

    //ensures id is positive, then attempts to delete node
    bool success = (id>0 && hashtable[hash(id)]->deleteNode(id));

    if (success) {
        count--;
    }

    return success;
}

int HashTable::getCount() {
    return count;
}

//only method allowed to print
void HashTable::printTable() {

    for (int i = 0; i<HASHTABLESIZE; i++) {
        std::cout << "Entry " << i+1 << ": ";
        hashtable[i]->printList();
    }

}

int HashTable::hash(int id) {
    return (id%HASHTABLESIZE);
}
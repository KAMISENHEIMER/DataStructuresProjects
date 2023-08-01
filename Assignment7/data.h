/*********************
Name: Kaden Misenheimer
Assignment 7: Hash Tables
Purpose: This contains the Data struct and the Node struct which allow the linked list to function. This file was made by Alexander Katrompas as part of Assignment 6: Linked Lists
**********************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */


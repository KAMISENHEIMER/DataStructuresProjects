/*********************
Name: Kaden Misenheimer
Challenge 2: FIFO
Purpose: This is the header file for fifo.cpp
**********************/

#ifndef FIFO_FIFO_H
#define FIFO_FIFO_H

#include "string"
#include <iostream>

//normally these would go in a data.h file of their own,
// but the instructions were very specific about only including the listed 4 files,
// so i believe this is another good place for these structs to go.
struct Data {
    int id;
    std::string data;
};

struct Node {
    Data data;
    Node *next;
};

class FIFO {
public:
    FIFO();
    ~FIFO();
    bool push(int, std::string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
private:
    Node *head;
    Node *tail;
};

#endif //FIFO_FIFO_H

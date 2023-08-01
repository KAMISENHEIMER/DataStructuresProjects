/*********************
Name: Kaden Misenheimer
Assignment 5: Stack
Purpose: This is the header file for stack.cpp
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define DEFAULT_SIZE 10

class Stack {

public:

    Stack(int);
    ~Stack();
    bool push(int, const string *);       //* in a declaration passes by reference (the original data)
    bool pop(Data *);
    bool peek(Data *);
    bool isEmpty();
    int getSize();

private:

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
};

#endif //STACK_H

/*********************
Name: Kaden Misenheimer
Assignment 4: Int Stack
Purpose: This is the header file for stack.cpp
**********************/

#ifndef ASSIGNMENT4_STACK_H
#define ASSIGNMENT4_STACK_H

#define MAX 10

class Stack {
public:
    Stack();
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
protected:
    int top;
    int a[MAX];
};

#endif //ASSIGNMENT4_STACK_H

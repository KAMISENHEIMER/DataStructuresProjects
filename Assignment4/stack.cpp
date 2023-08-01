/*********************
Name: Kaden Misenheimer
Assignment 4: Int Stack
Purpose: This is a class for the stack object. It contains the constructor and methods for the stack.
**********************/

#include "stack.h"

Stack::Stack() {
    top = -1;
}

bool Stack::push(int x) {
    bool success = (top<MAX-1);

    if (success) {
        top++;
        a[top] = x;
    }

    return success;
}

int Stack::pop() {
    if (isEmpty()) {
        throw -1;
    }

    return a[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        throw -1;
    }

    return a[top];
}

bool Stack::isEmpty() {
    return (top < 0);
}
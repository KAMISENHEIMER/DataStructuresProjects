/*********************
Name: Kaden Misenheimer
Assignment 5: Stack
Purpose: This file details the constructor, deconstructor, and all methods related to the stack ADT
**********************/

// each cpp includes ONLY it's header directly
#include "stack.h"



//constuctor
Stack::Stack(int s) {

    // if not 2 or greater, set stack size to a default of 10
    size = (s>1)?s:DEFAULT_SIZE;
    stack = new Data *[size];

    top = -1;
}

//deconstructor
Stack::~Stack() {

    for (int i = top; i > -1; i--) {
        delete stack[i];
    }

    delete[] stack;

}


//methods
bool Stack::push(int id, const string *info) {

    bool success = false;

    //ensures the stack is not full, id is positive (or zero), and info is not empty.
    if (top < size - 1 && id >=0 && info->length() > 0) {

        //creates new data struct
        Data *newData = new Data;

        //fills newData with the passed in "id" and "info"
        //as newData is a pointer, -> is used to set properties.
        //* is used on info to derefrence it, allowing access to the string and not the pointer
        newData->id = id;
        newData->information = *info;

        stack[++top] = newData;
        success = true;
    }

    return success;
}

bool Stack::pop(Data *ret) {

    bool success = false;

    if (!isEmpty()) {
        *ret = *stack[top];     //sets the reference pointing to the stack[top]
        delete stack[top--];    //deletes the pointer and decrements
        success = true;
    } else {                    //else statement ensures that there is no reason the wrong data would be stored in the return variable
        ret->id = -1;
        ret->information = "";
    }

    return success;

}

//same as pop without deleting and decrementing
bool Stack::peek(Data *ret) {
    bool success = false;

    if (!isEmpty()) {
        *ret = *stack[top];
        success = true;
    } else {
        ret->id = -1;
        ret->information = "";
    }

    return success;
}

bool Stack::isEmpty() {
    return (top < 0);
}

int Stack::getSize() {
    return size;
}

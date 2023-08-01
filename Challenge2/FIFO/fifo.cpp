/*********************
Name: Kaden Misenheimer
Challenge 2: FIFO
Purpose: This is a class for the FIFO (queue) object. It contains the constructor and methods.
**********************/

#include "fifo.h"

FIFO::FIFO() {
    head = nullptr;
    tail = nullptr;
}

FIFO::~FIFO() {
    if (head) {
        Node *location = head;
        Node *temp; //for deleting previous nodes
        while (location->next) {
            temp = location;
            location = location->next;
            delete temp;
        }
        delete location;
        head = nullptr;
    }
}

bool FIFO::push(int id, std::string *info) {
    bool success = false;

    if (id > 0 && info->length() > 0) {
        Node *newNode = new Node();
        newNode->data.id = id;
        newNode->data.data = *info;
        if (!head) {
            //empty case
            head = newNode;
            tail = newNode;
        } else {
            //at least one node case
            tail->next = newNode;
            tail = newNode;
        }
        success = true;
    }


    return success;
}

bool FIFO::pop(Data *ret) {
    bool success = false;

    if (head){
        if (head->next != nullptr){
            Node *temp = head; //keep current head to delete later
            *ret = head->data;
            head = head->next;
            delete temp; //delete the old head
        } else {
            *ret = head->data;
            //i thought i needed to delete the head right here,
            //though that was causing issues in testing, and setting the head to null seems to work fine,
            //but im worried i might not have completely fixed the issues
            head = nullptr;
            tail = nullptr;
        }
        success = true;
    }

    return success;
}

bool FIFO::peek(Data *ret) {
    bool success = false;
    if (head != nullptr){
        *ret = head->data;
        success = true;
    }
    return success;
}

bool FIFO::isEmpty() {
    return (!head);
}
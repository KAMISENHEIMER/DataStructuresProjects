/*********************
Name: Kaden Misenheimer
Assignment 6: Linked Lists
Purpose: This file details the constructor, deconstructor, and all methods related to the linked list ADT
**********************/

#include "linkedlist.h"

//constructor
LinkedList::LinkedList() {
    head = nullptr;
}

//deconstructor
LinkedList::~LinkedList() {
    clearList();
}


//methods
bool LinkedList::addNode(int id, string* info) {
    //id is greater than 0 and info is not empty
    bool validData = (id > 0 && info->length() > 0);

    //starts the same as validData (true if the data is valid, if there is a duplicate it will be set to false at the end)
    bool success = validData;

    if (validData) {
        if(!head) {
            //first node case
            insertNode('f',id, info);
        } else if(id < head->data.id) {
            //if new id is less than head id (new head node case)
            insertNode('h',id, info);
        } else {
            //catch duplicates, tail case, or find mid location
            Node* location = head;
            //while next is not null, and next location's id is greater than the new id (cannot be less than, or equal to new id)
            while (location->next && location->next->data.id < id) {
                location = location->next;
            }
            //figure out what ended the loop
            if (!location->next && location->data.id != id) {
                //tail case
                insertNode('t',id, info, location);
            } else if (location->data.id != id && location->next->data.id != id && location->next->data.id > id) {
                //middle case
                insertNode('m', id, info, location);
            } else {
                //found duplicate
                success = false;
            }
        }
    }

    return success;
}

bool LinkedList::deleteNode(int id) {
    bool success = false;
    Node* location = head;
    while (location && location->data.id != id) {
        location = location->next;
    }
    if (location && location->data.id == id) {
        //the id exists, now delete it

        if (!location->prev && !location->next) {
            //delete only, no need to re-point anything, linked list is empty
            head = nullptr;
        } else if (!location->prev) {
            //delete head
            head = head->next;
            head->prev = nullptr;
        } else if (!location->next) {
            //delete tail
            location->prev->next = nullptr;
        } else {
            //delete mid
            location->prev->next = location->next;
            location->next->prev = location->prev;
        }
        delete location;
        success = true;
    }
    return success;
}

bool LinkedList::getNode(int id, Data* returnData) {
    bool success = false;
    Node* location = head;
    while (location && location->data.id != id) {
        location = location->next;
    }
    if (location && location->data.id == id) {
        *returnData = location->data;
        success = true;
    }
    return success;
}

void LinkedList::printList(bool backward) {

    if (!head) {
        std::cout << "\tThe list is empty" << std::endl;
    } else {
        //head exists, begin printing
        int index = 0;
        Node* location = head;
        if (backward) {
            //print backward
            //finds the end of the linked list (without setting location to an nullptr)
            while (location->next) {
                location = location->next;
                index++;
            }
            //goes backwards through the linked list printing
            for (int i = index; i >= 0; i--) {
                std::cout << "\t" << i << ": " << location->data.id << " : " << location->data.data << std::endl;
                location = location->prev;
            }

        } else {
            //print forward
            while (location) {
                std::cout << "\t" << index++ << ": " << location->data.id << " : " << location->data.data << std::endl;
                location = location->next;
            }
        }
    }
}

int LinkedList::getCount() {
    int count = 0;
    Node* location = head;
    //while the location is not null
    while (location) {
        location = location->next;
        count++;
    }
    return count;
}

bool LinkedList::clearList() {

    if (head) {
        //head is not null, start clearing

        Node *location = head;

        //while the next location is not null
        while (location->next) {
            location = location->next;
            delete location->prev;
        }
        delete location;
        head = nullptr;

    }
    return true;
}

bool LinkedList::exists(int id) {
    Node* location = head;
    while (location && location->data.id != id) {
        location = location->next;
    }
    return (location && location->data.id==id);
}


//private methods
void LinkedList::createNode(Node *newNode, int id, string *info) {
    newNode->data.id = id;
    newNode->data.data = *info;
    newNode->next = nullptr;
    newNode->prev = nullptr;
}

void LinkedList::insertNode(char _case, int id, string *info, Node *location) {

    Node *newNode = new Node();
    createNode(newNode, id, info);

    switch (_case) {
        case 'f':
            insertFirstNode(newNode);
            break;
        case 'h':
            insertHeadNode(newNode);
            break;
        case 'm':
            insertMidNode(location, newNode);
            break;
        case 't':
            insertTailNode(location, newNode);
            break;
    }

}

void LinkedList::insertFirstNode(Node *newNode) {
    head = newNode;
}

void LinkedList::insertHeadNode(Node *newNode) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void LinkedList::insertMidNode(Node *location, Node *newNode) {
    location->next->prev = newNode;
    newNode->next = location->next;
    newNode->prev = location;
    location->next = newNode;
}

void LinkedList::insertTailNode(Node *location, Node *newNode) {
    newNode->prev = location;
    location->next = newNode;
}
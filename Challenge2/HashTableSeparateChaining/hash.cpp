/*********************
Name: Kaden Misenheimer
Challenge 2: Hash Tables: Separate Chaining
Purpose: This file details the constructor, deconstructor, and all methods related to the hash table ADT
**********************/

#include "hash.h"

//constructor
Hash::Hash() {

    heads = new Node *[HASHTABLESIZE];
    _count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++) {
        heads[i] = nullptr;
    }

}

//deconstructor
Hash::~Hash() {

    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (heads[i]) {
            //head is not null, start clearing

            Node *location = heads[i];

            if (location->next) {
                Node *temp;
                //set up temp 1 step behind to delete after location moves forward
                while (location->next) {
                    temp = location;
                    location = location->next;
                    delete temp;
                }
            }
            delete location;
            heads[i] = nullptr;
        }
    }

    delete[] heads;
}

//methods
bool Hash::addEntry(int id, std::string *info) {

    bool success = false;

    //valid data
    if (id >=0 && info->length() > 0) {
        if (!(heads[hash(id)])) {
            //empty list case
            Node *newNode = new Node();
            newNode->data.id = id;
            newNode->data.data = *info;

            heads[hash(id)] = newNode;
            success = true;
        } else {
            Node* location = heads[hash(id)];
            //keep going till find duplicate or nullptr
            while (location->next && location->data.id != id) {
                location = location->next;
            }
            //stopped at end of the list
            if (location->data.id != id) {
                Node *newNode = new Node();
                newNode->data.id = id;
                newNode->data.data = *info;

                location->next = newNode;
                success = true;
            }
        }

    }

    //increases count if adding was successful
    if (success) {
        _count++;
    }

    return success;
}

bool Hash::getEntry(Data *ret, int id) {
    bool success = false;

    //ensures id is positive
    if (id>0) {
        //ensures the hash has a head
        if (heads[hash(id)]) {
            Node *location = heads[hash(id)];
            //keep going till you find the id or nullptr
            while (location->next && location->data.id != id) {
                location = location->next;
            }
            //stopped at the correct value
            if (location->data.id == id) {
                *ret = location->data;
                success = true;
            }
        }
    }

    return success;
}

bool Hash::removeEntry(int id) {

    bool success = false;

    //ensures id is positive
    if (id>0) {
        //ensures the hash has a head
        if (heads[hash(id)]) {

            Node *location = heads[hash(id)];
            if (location->data.id == id) {
                //remove head case
                if (location->next) {
                    //new head
                    heads[hash(id)] = heads[hash(id)]->next;
                } else {
                    //no head
                    heads[hash(id)] = nullptr;
                }
                delete location;
                success = true;
            } else {
                //not a head case, start to search through rest of list
                if (location->next) {
                    //set up temp location right behind location for connecting nodes after deleting
                    Node *temp = location;
                    location = location->next;
                    //keep going till you find the id or nullptr
                    while (location->next && location->data.id != id) {
                        location = location->next;
                        temp = temp->next;
                    }
                    //stopped at the desired value
                    if (location->data.id == id) {
                        if (location->next) {
                            //middle case
                            temp->next = location->next;
                        } else {
                            //tail case
                            temp->next = nullptr;
                        }
                        delete location;
                        success = true;
                    }

                }
            }
        }
    }

    //decreases count if removing was successful
    if (success) {
        _count--;
    }

    return success;
}

int Hash::count() {
    return _count;
}

//only method allowed to print
void Hash::displayTable() {

    for (int i = 0; i<HASHTABLESIZE; i++) {
        std::cout << "Entry " << i+1 << ": ";

        if (!heads[i]) {
            std::cout << "EMPTY" << std::endl;
        } else {
            //head exists, begin printing
            Node* location = heads[i];
            while (location) {
                std::cout << location->data.id;
                if (location->next) {
                    //if there is another location after, add an arrow
                    std::cout << " --> ";
                }
                location = location->next;
            }
            std::cout << std::endl;

        }

    }

}

int Hash::hash(int id) {
    return (id%HASHTABLESIZE);
}
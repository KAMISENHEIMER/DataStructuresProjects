/*********************
Name: Kaden Misenheimer
Assignment 8: Binary Search Tree
Purpose: This file contains the constructor, deconstructor, and methods for the Binary Search Tree ADT.
**********************/

#include "bintree.h"

//constructor
BinTree::BinTree() {
    root = nullptr;
    count = 0;
}

//deconstructor
BinTree::~BinTree() {
    clear();
}


//public methods
bool BinTree::isEmpty() {
    return (count==0);
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data *ret) {
    bool success = false;
    if (root) {
        *ret = root->data;
        success = true;
    }
    return success;
}

void BinTree::displayTree() {
    displayPreOrder();
    displayInOrder();
    displayPostOrder();
}


//public methods with overloads
void BinTree::clear() {
    if (root) {
        clear(root);
        root = nullptr;
    }
}

bool BinTree::addNode(int id, const string *info) {
    bool validData = (id > 0 && info->length() > 0);
    bool success = false;
    if (validData) {
        //creates data node with valid data
        DataNode *node = new DataNode();
        node->data.id = id;
        node->data.information = *info;

        //calls private addNode, and tracks its return value
        success = addNode(node, &root);
    }
    if (success) {
        count++;
    }
    return success;
}

bool BinTree::removeNode(int id) {
    int tempcount = count;
    if (root) {
        root = removeNode(id,root);
    }
    return (tempcount>count);
}

bool BinTree::getNode(Data *ret, int id) {
    bool success = false;
    if (root && id>0) {
        success = getNode(ret,id,root);
    }
    return success;
}

bool BinTree::contains(int id) {
    bool success = false;
    if (root && id>0) {
        success = contains(id,root);
    }
    return success;
}

int BinTree::getHeight() {
    int maxheight = 0;
    if (root) {
        int leftheight = getHeight(root->left);
        int rightheight = getHeight(root->right);
        maxheight = ((leftheight > rightheight) ? leftheight : rightheight) + 1;
    }
    return maxheight;
}

void BinTree::displayPreOrder() {
    std::cout << "Pre-Order Traversal" << std::endl;
    if (root) {
        displayPreOrder(root);
    }
    std::cout << std::endl;
}

void BinTree::displayPostOrder() {
    std::cout << "Post-Order Traversal" << std::endl;;
    if (root) {
        displayPostOrder(root);
    }
    std::cout << std::endl;
}

void BinTree::displayInOrder() {
    std::cout << "In-Order Traversal" << std::endl;
    if (root) {
        displayInOrder(root);
    }
    std::cout << std::endl;
}


//private overload methods
void BinTree::clear(DataNode *node) {
    if(node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool BinTree::addNode(DataNode *node, DataNode **newroot) {
    //node is the node we want to add, newroot is the current node that we are testing
    bool success = false;
    if (!(*newroot)) {
        //if there is no node here, insert the node.
        *newroot = node;
        success = true;
    } else {
        if (node->data.id < (*newroot)->data.id) {
            //the node we want to is less than current node, so traverse left
            success = addNode(node,&((*newroot)->left));
        } else {
            //the node we want is greater than (or equal) to the current node, so traverse right
            success = addNode(node,&((*newroot)->right));
        }
    }
    return success;
}

DataNode* BinTree::removeNode(int id, DataNode *node) {

    if (node) {
        //current node is not empty
        if (id < node->data.id) {
            //traverse left
            node->left = removeNode(id, node->left);
        } else if (id > node->data.id) {
            //traverse right
            node->right = removeNode(id, node->right);
        } else {
            //node id is equal to desired id, remove node

            DataNode *temp;
            if (!(node->left) && !(node->right)) {
                //no children
                delete node;
                count--;
                node = nullptr;
            } else if (!(node->right)) {
                //only left child
                DataNode *temp = node;
                node = node->left;
                delete temp;
                count--;
            } else if (!(node->left)) {
                //only right child
                DataNode *temp = node;
                node = node->right;
                delete temp;
                count--;
            } else {
                //2 children
                DataNode *temp = minValueNode(node->right);
                node->data.id = temp->data.id;
                node->data.information = temp->data.information;
                node->right = removeNode(temp->data.id, node->right);
            }

        }
    }

    return node;
}

bool BinTree::getNode(Data *ret, int id, DataNode *node) {
    bool success = false;
    if (node) {
        if (node->data.id == id) {
            *ret = node->data;
            success = true;
        }
        else if (node->data.id>id) {
            //if we are currently greater than the desired id, traverse left
            success = getNode(ret, id, node->left);
        } else {
            //if we are currently less than the desired id, traverse right
            success = getNode(ret, id, node->right);
        }
    }
    return success;
}

bool BinTree::contains(int id, DataNode *node) {
    bool success = false;
    if (node) {
        if (node->data.id == id) {
            success = true;
        }
        else if (id < node->data.id) {
            //if desired id is less than current id, traverse left
            success = contains(id, node->left);
        } else {
            //if we are currently less than the desired id, traverse right
            success = contains(id, node->right);
        }
    }
    return success;
}

int BinTree::getHeight(DataNode *node) {
    int maxheight = 0;
    if (node) {
        int leftheight = getHeight(node->left);
        int rightheight = getHeight(node->right);
        maxheight = ((leftheight > rightheight) ? leftheight : rightheight) + 1;
    }
    return maxheight;

    return 0;
}

void BinTree::displayPreOrder(DataNode *node) {
    if(node) {
        std::cout << node->data.id << " " << node->data.information << std::endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void BinTree::displayPostOrder(DataNode *node) {
    if(node) {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        std::cout << node->data.id << " " << node->data.information << std::endl;
    }
}

void BinTree::displayInOrder(DataNode *node) {
    if(node) {
        displayInOrder(node->left);
        std::cout << node->data.id << " " << node->data.information << std::endl;
        displayInOrder(node->right);
    }
}

DataNode* BinTree::minValueNode(DataNode *node) {
    DataNode *current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}
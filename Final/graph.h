/*********************
Name: Kaden Misenheimer
Final: Graphs
Purpose: This is the header file for graph.cpp, it contains the prototypes and attributes for the Undirected Unweighted Graph ADT.
**********************/

#ifndef FINAL_GRAPH_H
#define FINAL_GRAPH_H

#include <iostream>
#include <queue>
#include "data.h"

class Graph {

public:

    //constructor
    Graph();

    //deconstructor
    ~Graph();

    //public methods
    bool isEmpty();
    int getVertCount();
    int getEdgeCount();
    bool vertexExists(int);
    bool edgeExists(int, int);
    bool addVertex(int, const string*);
    bool removeVertex(int);
    bool addEdge(int,int);
    bool removeEdge(int,int);
    bool getVertex(Data*, int);
    void printGraphDepthFirst(int);
    void printGraphBreadthFirst(int);
    void clearGraph();

//depthFirstSearch, use stack
//breadthFirstSearch, use queue

private:
    //private methods for recursion
    void printGraphDepthFirst(int, std::vector<bool>&); //passes reference to the bool vector, so we can edit the original directly, this ensures the bool vector is actually accurate and holds where we've traveled to
    void printGraphBreadthFirst(std::vector<bool>&, std::queue<int>*);

    //helpers for printing functions
    int edgesIdToVerticiesId(int, int);
    int verticiesIndexOfId(int vertexId);


        //properties
    int vertexCount;
    int edgeCount;
    std::vector<Vertex> verticies;

};


#endif //FINAL_GRAPH_H

/*********************
Name: Kaden Misenheimer
Final: Graphs
Purpose: This file contains the constructor, deconstructor, and methods for an Undirected Unweighted Graph ADT.
**********************/

#include "graph.h"

//constructor
Graph::Graph() {
    vertexCount = 0;
    edgeCount = 0;
}

//deconstructor
Graph::~Graph() {
    clearGraph();
}

//public methods
bool Graph::isEmpty() {
    return (vertexCount==0);
}

int Graph::getVertCount() {
    return vertexCount;
}

int Graph::getEdgeCount() {
    return edgeCount;
}

bool Graph::vertexExists(int id) {
    //search through verticies list and success true if one of them is the right id
    bool success = false;
    if (id>0) {
        for (int i = 0; i < vertexCount; i++) {
            if (verticies[i].data.id == id) {
                success = true;
            }
        }
    }
    return success;
}

bool Graph::edgeExists(int id1, int id2) {
    //search through verticies list to find id1, then search through id2 and return true if the connection is found
    bool success = false;

    //finds id1
    int vertex = verticiesIndexOfId(id1);
    if (vertex>-1)
    {
        //id2 loop
        for (int i = 0; i < verticies[vertex].edges.size(); i++) {
            if (verticies[vertex].edges[i] == id2) {
                success = true;
            }
        }

    }
    return success;
}

bool Graph::addVertex(int id, const string *info) {
    bool success = false;
    //check if the data is valid
    if (id > 0 && info->length() > 0) {
        //check for duplicate id in the graph
        success = (verticiesIndexOfId(id)==-1);
    }

    //if valid and no duplicate, create and add vertex to graph
    if (success) {
        Vertex vertex;
        vertex.data.id = id;
        vertex.data.data = *info;
        verticies.push_back(vertex);
        vertexCount++;
    }

    return success;
}

//todo this function should be better formated, likely using a "clear vertex" function
bool Graph::removeVertex(int id) {
    //search through verticies list and delete the vertex if one of them is the right id
    //very important that this method then clears any edge that connects to this vertex
    bool success = false;
    if (id>0) {
        int vertex = verticiesIndexOfId(id);
        if (vertex >-1) {
            verticies[vertex].edges.clear(); //clears edges on this object
            verticies.erase(verticies.begin()+vertex);    //erases this vertex
            //begin deleting all edges that link to this id
            for (int i = 0; i < vertexCount; i++) {
                for (int j = 0; j < verticies[i].edges.size(); j++) {
                    //for each edge in each vertex, delete it if it is id
                    if (verticies[i].edges[j] == id) {
                        verticies[i].edges.erase(verticies[i].edges.begin()+j);
                        edgeCount--;
                    }
                }
            }
            vertexCount--;
            success = true;

        }
        return success;
    }
    return false;
}

bool Graph::addEdge(int id1, int id2) {
    bool success = false;
    //valid ids check (both above zero, not the same, and edge does not already exist)
    if (id1 > 0 && id2 > 0 && id1 != id2 && !edgeExists(id1, id2)) {
        int id1Pos = -1;
        int id2Pos = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (verticies[i].data.id == id1) {
                id1Pos = i;
            } else if (verticies[i].data.id == id2) {
                id2Pos = i;
            }
        }
        if (id1Pos != -1 && id2Pos != -1) {
            //they have both been found, add both edges
            verticies[id1Pos].edges.push_back(id2);
            verticies[id2Pos].edges.push_back(id1);
            edgeCount++;
            success = true;
        }
    }
    return success;
}

bool Graph::removeEdge(int id1, int id2) {
    bool success = false;
    //valid ids check (above zero and not the same)
    if (id1 > 0 && id2 > 0 && id1 != id2) {
        //ensure edges exist
        int edge1Pos = -1;
        int vert1Pos = -1;
        int edge2Pos = -1;
        int vert2Pos = -1;
        //find vertex
        for (int i = 0; i < vertexCount; i++) {
            if (verticies[i].data.id == id1) {
                //find edge
                for (int j = 0; j < verticies[i].edges.size(); j++) {
                    if (verticies[i].edges[j] == id2) {
                        vert1Pos = i;
                        edge2Pos = j;
                    }
                }
            } else if (verticies[i].data.id == id2) {
                for (int j = 0; j < verticies[i].edges.size(); j++) {
                    if (verticies[i].edges[j] == id1) {
                        vert2Pos = i;
                        edge1Pos = j;
                    }
                }
            }
        }
        if (vert1Pos > -1) {
            //this if statement could be a lot longer, but if addEdge is functioning correctly, there is no need for anything other than this
            //delete both edges
            //vector.erase requires an iterator, which means i have to use .begin of the vector and add my desired location to it
            verticies[vert1Pos].edges.erase(verticies[vert1Pos].edges.begin()+edge2Pos);
            verticies[vert2Pos].edges.erase(verticies[vert2Pos].edges.begin()+edge1Pos);
            edgeCount--;
            success = true;
        }
    }
    return success;
}

bool Graph::getVertex(Data *ret, int id) {
    //search through verticies list and return data if one of them is the right id
    bool success = false;
    if (id>0) {
        int vertex = verticiesIndexOfId(id);
        if (vertex>-1) {
            success = true;
            *ret = verticies[vertex].data;
        }
    }
    return success;
}

void Graph::clearGraph() {
    verticies.clear();
    vertexCount = 0;
    edgeCount = 0;
}

void Graph::printGraphDepthFirst(int id) {
    std::cout << "Printing Depth First From " << id << ": ";
    if (vertexExists(id)) {
        //initializes a list of bools to keep track if we've already traversed a vector
        std::vector<bool> visited(vertexCount, false);
        printGraphDepthFirst(id, visited);
        std::cout << std::endl;
    } else {
        std::cout << "Invalid Starting Point" << std::endl;
    }
}

//private recursive
void Graph::printGraphDepthFirst(int id, std::vector<bool> &visited) {
    //set current vertex as visited and print its id
    int vertex = verticiesIndexOfId(id);
    std::cout << verticies[vertex].data.id << ", ";
    visited[vertex] = true;
    //then repeat for all edges connected to node (that have not already been traversed to)
    for (int i = 0; i < verticies[vertex].edges.size(); i++) {
        //find id of current edge in boolean list
        int edgeId = edgesIdToVerticiesId(vertex, i);
        if (!(visited[edgeId])) {
            printGraphDepthFirst(verticies[vertex].edges[i], visited);
        }
    }
}


void Graph::printGraphBreadthFirst(int id) {
    std::cout << "Printing Breadth First From " << id << ": ";
    if (vertexExists(id)) {
        //initializes a list of bools to keep track if we've already traversed a spot
        std::vector<bool> visited(vertexCount, false);
        //initializes queue, as Breadth first printing requires slightly different process
        std::queue<int> printOrder;
        printOrder.push(id);
        visited[verticiesIndexOfId(id)] = true;
        printGraphBreadthFirst(visited, &printOrder);



        std::cout << std::endl;
    } else {
        std::cout << "Invalid Starting Point" << std::endl;
    }
}

void Graph::printGraphBreadthFirst(std::vector<bool> &visited, std::queue<int> *printOrder) {

    while (!printOrder->empty()) {
        //while the print order still has values
        int currentVertexId = printOrder->front();
        std::cout << currentVertexId << ", ";
        printOrder->pop();

        //add all edges connected to this vertex (that are unvisited), then mark them as visited
        int vertexIndex = verticiesIndexOfId(currentVertexId);
        for (int i = 0; i < verticies[vertexIndex].edges.size(); i++) {
            int edgeId = edgesIdToVerticiesId(vertexIndex, i);
            if (!visited[edgeId]) {
                visited[edgeId] = true;
                printOrder->push(verticies[edgeId].data.id);
            }
        }

    }
}

int Graph::edgesIdToVerticiesId(int vertexId, int edgeId) {
    //helper method to find where an id is in the verticies vector, used for finding edges in the boolean lists used for printing
    int ret = -1;
    for (int i = 0; i < vertexCount; i++) {
        if (verticies[i].data.id == verticies[vertexId].edges[edgeId])
            ret = i;
    }
    return ret;
}

int Graph::verticiesIndexOfId(int vertexId) {
    //helper method to find the index of an id in the verticies vector
    int ret = -1;
    for (int i = 0; i < vertexCount; i++) {
        if (verticies[i].data.id == vertexId) {
            ret = i;
        }
    }
    return ret;
}
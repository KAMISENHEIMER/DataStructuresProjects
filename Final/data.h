/*********************
Name: Kaden Misenheimer
Final: Graphs
Purpose: This contains the Data struct and the Vertex struct which allow the graph to function.
**********************/

#ifndef FINAL_DATA_H
#define FINAL_DATA_H

#include "string"
#include <vector>

using std::string;

struct Data {
    int id;
    string data;
};

struct Vertex {
    Data data;
    std::vector<int> edges;
};

#endif //FINAL_DATA_H


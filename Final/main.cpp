/*********************
Name: Kaden Misenheimer
Final: Graphs
Purpose: This file fully and extensively tests the graph object and its methods.
**********************/

#include "main.h"

int main(int argc, char** argv) {

    //seeds random function
    srand(time(NULL));

    //random number between min and max
    const int testdatasize = MINTESTDATA + (rand() % (MAXTESTDATA-MINTESTDATA+1));
    //arrays for ids and data
    int testIds[testdatasize];
    std::string testData[testdatasize];

    //fills testIds and testData with appropriate data
    char tempString[DATALENGTH];
    for (int i = 0; i < testdatasize; i++) {
        testIds[i] = rand() % MAXID + 1;
        for (int j = 0; j < DATALENGTH-1; j++) {
            tempString[j] = 'A' + i;
        }
        tempString[DATALENGTH-1] = '\0'; //marks the end of a string
        testData[i] = tempString; //turns the character array to a string
    }

    //creates empty data and negative id
    testData[testdatasize-2] = "";
    testIds[testdatasize-1] = -1;
    testData[testdatasize-1] = "negative data";

    //displaying test data
    std::cout << "Displaying Test Data: " << testdatasize << " Items" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << testIds[i] << " : " << testData[i] << std::endl;
    }
    std::cout << std::endl;


    //creates graph
    Graph graph;
    //creates data object for returning
    Data returnData;
    //creates 2 ints for picking random data for testing
    int randomId1, randomId2;


    //EMPTY TESTS
    std::cout << "BEGINNING EMPTY TESTS" << std::endl;
    if (graph.isEmpty()) {
        std::cout << "Graph is empty" << std::endl;
    }else {
        std::cout << "Graph is not empty" << std::endl;
    }
    std::cout << graph.getVertCount() << " verticies" << std::endl;
    std::cout << graph.getEdgeCount() << " edges" << std::endl;

    randomId1 = rand() % testdatasize;
    std::cout << "Getting " << testIds[randomId1] << ": ";
    if (graph.getVertex(&returnData, testIds[randomId1])) {
        std::cout << "Got " << returnData.data << std::endl;
    }else {
        std::cout << "Failed" << std::endl;
    }

    randomId1 = rand() % testdatasize;
    randomId2 = rand() % testdatasize;
    std::cout << "Testing For Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": ";
    if (graph.edgeExists(testIds[randomId1], testIds[randomId2])) {
        std::cout << "Exists" << std::endl;
    }else {
        std::cout << "Not exists" << std::endl;
    }

    std::cout << "Clearing Graph" << std::endl;
    graph.clearGraph();

    graph.printGraphDepthFirst(testIds[0]);
    graph.printGraphBreadthFirst(testIds[0]);


    //FILLING GRAPH
    std::cout << "\nFILLING WITH TEST DATA AND EDGES" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Adding Vertex " << testIds[i] << " : " << testData[i] << ": ";

        if (graph.addVertex(testIds[i],&testData[i])) {
            std::cout << "Added" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }
    }
    for (int i = 0; i < testdatasize; i++) {
        randomId1 = rand() % testdatasize;
        randomId2 = rand() % testdatasize;
        std::cout << "Adding Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": ";
        if (graph.addEdge(testIds[randomId1], testIds[randomId2])) {
            std::cout << "Added" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }
    }


    //FULL TESTS
    std::cout << "\nBEGINNING FULL TESTS" << std::endl;
    if (graph.isEmpty()) {
        std::cout << "Graph is empty" << std::endl;
    }else {
        std::cout << "Graph is not empty" << std::endl;
    }
    std::cout << graph.getVertCount() << " verticies" << std::endl;
    std::cout << graph.getEdgeCount() << " edges" << std::endl;

    randomId1 = rand() % testdatasize;
    std::cout << "Getting " << testIds[randomId1] << ": ";
    if (graph.getVertex(&returnData, testIds[randomId1])) {
        std::cout << "Got " << returnData.data << std::endl;
    }else {
        std::cout << "Failed" << std::endl;
    }

    randomId1 = rand() % testdatasize;
    randomId2 = rand() % testdatasize;
    std::cout << "Testing For Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": ";
    if (graph.edgeExists(testIds[randomId1], testIds[randomId2])) {
        std::cout << "Exists" << std::endl;
    }else {
        std::cout << "Does not exist" << std::endl;
    }

    graph.printGraphDepthFirst(testIds[0]);
    graph.printGraphBreadthFirst(testIds[0]);


    //REMOVING HALF THE DATA
    std::cout << "\nREMOVING HALF TEST DATA" << std::endl;
    for (int i = 0; i <(testdatasize/2)-1; i++) {
        std::cout << "Removing " << testIds[i] << ": ";
        if (graph.removeVertex(testIds[i])) {
            std::cout << "Removed" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }
    }

    //RANDOM TESTS
    std::cout << "\nBEGINNING RANDOM TESTS" << std::endl;
    for (int i = 0; i < testdatasize*testdatasize; i++) {
        //picks which test case to do
        int testCase = (rand() % 12) + 1;

        //picks which pieces of test data to interact with
        randomId1 = rand() % testdatasize;
        randomId2 = rand() % testdatasize;

        switch (testCase) {
            case 1:
                //add vertex
                std::cout << "Adding Vertex " << testIds[randomId1] << " : " << testData[randomId1] << ": ";
                if (graph.addVertex(testIds[randomId1],&testData[randomId1])) {
                    std::cout << "Added" << std::endl;
                } else {
                    std::cout << "Failed" << std::endl;
                }
                break;
            case 2:
                //remove vertex
                std::cout << "Removing " << testIds[randomId1] << ": ";
                if (graph.removeVertex(testIds[randomId1])) {
                    std::cout << "Removed" << std::endl;
                } else {
                    std::cout << "Failed" << std::endl;
                }
                break;
            case 3:
                //get vertex
                std::cout << "Getting " << testIds[randomId1] << ": ";
                if (graph.getVertex(&returnData, testIds[randomId1])) {
                    std::cout << "Got " << returnData.data << std::endl;
                }else {
                    std::cout << "Failed" << std::endl;
                }
                break;
            case 4:
                //vertex exists
                std::cout << "Testing For Vertex " << testIds[randomId1] << ": ";
                if (graph.vertexExists(testIds[randomId1])) {
                    std::cout << "Exists" << std::endl;
                }else {
                    std::cout << "Does not exist" << std::endl;
                }
            case 5:
                //add edge
                std::cout << "Adding Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": ";
                if (graph.addEdge(testIds[randomId1], testIds[randomId2])) {
                    std::cout << "Added" << std::endl;
                } else {
                    std::cout << "Failed" << std::endl;
                }
                break;
            case 6:
                //remove edge
                std::cout << "Removing Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": " ;
                if (graph.removeEdge(testIds[randomId1], testIds[randomId2])) {
                    std::cout << "Removed" << std::endl;
                } else {
                    std::cout << "Failed" << std::endl;
                }
                break;
            case 7:
                //edge exists
                std::cout << "Testing For Edge Between " << testIds[randomId1] << " and " << testIds[randomId2] << ": ";
                if (graph.edgeExists(testIds[randomId1], testIds[randomId2])) {
                    std::cout << "Exists" << std::endl;
                }else {
                    std::cout << "Does not exist" << std::endl;
                }
                break;
            case 8:
                //vertex count
                std::cout << graph.getVertCount() << " verticies" << std::endl;
                break;
            case 9:
                //edge count
                std::cout << graph.getEdgeCount() << " edges" << std::endl;
                break;
            case 10:
                //is empty
                if (graph.isEmpty()) {
                    std::cout << "Graph is empty" << std::endl;
                }else {
                    std::cout << "Graph is not empty" << std::endl;
                }
                break;
            case 11:
                //depth first print
                graph.printGraphDepthFirst(testIds[randomId1]);
                break;
            case 12:
                //breadth first print
                graph.printGraphBreadthFirst(testIds[randomId1]);
                break;

        }
    }

    std::cout << "\nFINAL DISPLAY" << std::endl;
    if (graph.isEmpty()) {
        std::cout << "Graph is empty" << std::endl;
    }else {
        std::cout << "Graph is not empty" << std::endl;
    }
    std::cout << graph.getVertCount() << " verticies" << std::endl;
    std::cout << graph.getEdgeCount() << " edges" << std::endl;
    randomId1 = rand() % testdatasize;
    graph.printGraphDepthFirst(testIds[randomId1]);
    graph.printGraphBreadthFirst(testIds[randomId1]);


}
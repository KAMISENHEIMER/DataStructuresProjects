/*********************
Name: Kaden Misenheimer
Challenge 2: FIFO
Purpose: This file is for testing the FIFO class, it fully tests each method in every state the fifo can be in.
**********************/
#include "main.h"

int main(int argc, char** argv) {

    //seeds random function
    srand(time(NULL));

    //creates test data to be used in testing of FIFO
    //this segment of code was very heavily inspired by the given code in Assignment 7
    const int testdatasize = BASE + (rand() % OFFSET + 1);  //21-26 random entries
    int testIds[testdatasize];
    std::string testData[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        testIds[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        testData[i] = buffer;
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


    //creates data object to be used for displaying from FIFO
    Data returnData;

    //creates new FIFO object
    FIFO queue;


    //EMPTY TESTS
    std::cout << "BEGINNING TESTS WITH EMPTY FIFO" << std::endl;

    std::cout << "isEmpty: ";
    if (queue.isEmpty()) {
        std::cout << "FIFO is empty" << std::endl;
    } else {
        std::cout << "FIFO is not empty" << std::endl;
    }

    std::cout << "Peek: ";
    if (queue.peek(&returnData)) {
        std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
    } else {
        std::cout << "Error Peeking (Empty)" << std::endl;
    }

    std::cout << "Pop: ";
    if (queue.pop(&returnData)) {
        std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
    } else {
        std::cout << "Error Popping (Empty)" << std::endl;
    }

    std::cout << "Pushing " << testIds[0] << ": ";
    if (queue.push(testIds[0],&testData[0])) {
        std::cout << "Pushed" << std::endl;
    } else {
        std::cout << "Error Pushing (Bad Data)" << std::endl;
    }


    //FILLING WITH HALF TEST DATA
    std::cout << "\nFILLING FIFO WITH HALF TEST DATA" << std::endl;
    for (int i = 0; i<testdatasize/2; i++) {
        std::cout << "Pushing " << testIds[i] << ": ";
        if (queue.push(testIds[i], &testData[i])) {
            std::cout << "Pushed" << std::endl;
        } else {
            std::cout << "Error Pushing (Bad Data)" << std::endl;
        }

    }

    //HALF FULL TESTS
    std::cout << "\nBEGINNING TESTS WITH FILLED FIFO" << std::endl;

    std::cout << "isEmpty: ";
    if (queue.isEmpty()) {
        std::cout << "FIFO is empty" << std::endl;
    } else {
        std::cout << "FIFO is not empty" << std::endl;
    }

    std::cout << "Peek: ";
    if (queue.peek(&returnData)) {
        std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
    } else {
        std::cout << "Error Peeking (Empty)" << std::endl;
    }

    std::cout << "Pop: ";
    if (queue.pop(&returnData)) {
        std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
    } else {
        std::cout << "Error Popping (Empty)" << std::endl;
    }

    std::cout << "Pushing " << testIds[0] << ": ";
    if (queue.push(testIds[0],&testData[0])) {
        std::cout << "Pushed" << std::endl;
    } else {
        std::cout << "Error Pushing (Bad Data)" << std::endl;
    }

    //RANDOM TESTS
    std::cout << "\nBEGINNING RANDOM CASE TESTS ON FIFO" << std::endl;



    for (int i = 0; i<testdatasize*testdatasize; i++) {
        //picks which test case to do
        int testCase = (rand() % 4) + 1;
        std::cout << "CASE: " << testCase << std::endl;

        //picks which piece of test data to push
        int randomData = (rand() % testdatasize);

        switch (testCase) {
            case 1:
                //push case
                std::cout << "Pushing " << testIds[randomData] << ": ";
                if (queue.push(testIds[randomData],&testData[randomData])) {
                    std::cout << "Pushed" << std::endl;
                } else {
                    std::cout << "Error Pushing (Bad Data)" << std::endl;
                }
                break;
            case 2:
                //pop case
                std::cout << "Pop: ";
                if (queue.pop(&returnData)) {
                    std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
                } else {
                    std::cout << "Error Popping (Empty)" << std::endl;
                }
                break;
            case 3:
                //peek case
                std::cout << "Peek: ";
                if (queue.peek(&returnData)) {
                    std::cout << "id: " << returnData.id << " data: " << returnData.data << std::endl;
                } else {
                    std::cout << "Error Peeking (Empty)" << std::endl;
                }
                break;
            case 4:
                //isEmpty case
                std::cout << "isEmpty: ";
                if (queue.isEmpty()) {
                    std::cout << "FIFO is empty" << std::endl;
                } else {
                    std::cout << "FIFO is not empty" << std::endl;
                }
                break;
        }

    }

    return 0;
}
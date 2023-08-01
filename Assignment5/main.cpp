/*
 * your header here
 * 
 */

#include "main.h"

int main(int argc, char **argv) {

    srand(time(NULL));

    //ensures the input only has 2 inputs (the application name and the size), and ensures the second input is an integer
    bool validInput = false;
    if (argc == 2 && isNumber(argv[1])) {
        validInput = true;
    }

    if (validInput) {
        //BEGIN EXTENSIVE TESTING

        //creates stack, uses second parameter (converted to an int) as size
        Stack stack(std::stoi(argv[1]));

        //data object for pop and peek methods
        Data returnData;

        //objects for push methods
        int dataId;
        std:string dataInfo;

        //printing size of stack (so user knows if the stack went to the default size)
        std::cout << "size: " << stack.getSize() << std::endl;

        //EMPTY TESTS
        std::cout << "Beginning Empty Tests:" << std::endl;

        //isEmpty on empty stack
        if (stack.isEmpty()) {
            std::cout << "stack is empty" << std::endl;
        } else {
            std::cout << "stack is not empty" << std::endl;
        }

        //peek on empty stack
        if (stack.peek(&returnData)) {
            std::cout << "peeked, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: peek underflow, stack is empty" << std::endl;
        }

        //pop on empty stack
        if (stack.pop(&returnData)) {
            std::cout << "popped, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: pop underflow, stack is empty" << std::endl;
        }

        //FILLING TO HALF FULL, AND HALF FULL TESTS
        std::cout << "" << std::endl;
        std::cout << "Filling To Half Full:" << std::endl;

        //filling to half full
        for (int i = 0; i < stack.getSize()/2; i++) {
            rand_int(&dataId);
            rand_string(&dataInfo);
            if (stack.push(dataId, &dataInfo)) {
                std::cout << "pushed, id: " << dataId << "  info: " << dataInfo << std::endl;
            } else {
                std::cout << "Error: pushed invalid input (id: " << dataId << ", info: " << dataInfo << ")" << std::endl;
            }
        }

        std::cout << "" << std::endl;
        std::cout << "Beginning Half Full Tests:" << std::endl;

        //isEmpty on half full stack
        if (stack.isEmpty()) {
            std::cout << "stack is empty" << std::endl;
        } else {
            std::cout << "stack is not empty" << std::endl;
        }

        //peek on half full stack
        if (stack.peek(&returnData)) {
            std::cout << "peeked, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: peek underflow, stack is empty" << std::endl;
        }

        //pop on half full stack
        if (stack.pop(&returnData)) {
            std::cout << "popped, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: pop underflow, stack is empty" << std::endl;
        }

        //FILLING TO FULL, AND FULL TESTS
        std::cout << "" << std::endl;
        std::cout << "Filling To Full:" << std::endl;

        //filling past full
        for (int i = 0; i < stack.getSize(); i++) {         //ideally i would keep filling it till its full, but i have no isFull method, so i will just over fill the stack by about half to account for invalid data errors.
            rand_int(&dataId);
            rand_string(&dataInfo);
            if (stack.push(dataId, &dataInfo)) {
                std::cout << "pushed, id: " << dataId << "  info: " << dataInfo << std::endl;
            } else {
                std::cout << "Error: pushed invalid input (id: " << dataId << ", info: " << dataInfo << ") or full stack overflow" << std::endl;
            }
        }

        std::cout << "Beginning Full Tests:" << std::endl;

        //isEmpty on full stack
        if (stack.isEmpty()) {
            std::cout << "stack is empty" << std::endl;
        } else {
            std::cout << "stack is not empty" << std::endl;
        }

        //peek on full stack
        if (stack.peek(&returnData)) {
            std::cout << "peeked, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: peek underflow, stack is empty" << std::endl;
        }

        //pop on full stack
        if (stack.pop(&returnData)) {
            std::cout << "popped, id: " << returnData.id << "  info: " << returnData.information << std::endl;
        } else {
            std::cout << "Error: pop underflow, stack is empty" << std::endl;
        }

        //popping half the stack to begin random testing
        std::cout << "Popping Stack Till Half Full:" << std::endl;

        for (int i = 0; i < stack.getSize()/2; i++) {
            if (stack.pop(&returnData)) {
                std::cout << "popped, id: " << returnData.id << "  info: " << returnData.information << std::endl;
            } else {
                std::cout << "Error: pop underflow, stack is empty" << std::endl;
            }
        }

        //BEGINNING RANDOM TESTS
        std::cout << "" << std::endl;
        std::cout << "Beginning Random Tests:" << std::endl;

        //loop for all random tests
        for (int i =0; i<stack.getSize()*stack.getSize()*TEST_AMOUNT_MULTIPLIER; i++) {
            int testCase = (rand() % 4) + 1;
            switch (testCase) {
                case 1:
                    //pop case
                    if (stack.pop(&returnData)) {
                        std::cout << "popped, id: " << returnData.id << "  info: " << returnData.information << std::endl;
                    } else {
                        std::cout << "Error: pop underflow, stack is empty" << std::endl;
                    }
                    break;
                case 2:
                    //peek case
                    if (stack.peek(&returnData)) {
                        std::cout << "peeked, id: " << returnData.id << "  info: " << returnData.information << std::endl;
                    } else {
                        std::cout << "Error: peek underflow, stack is empty" << std::endl;
                    }
                    break;
                case 3:
                    //push case;
                    rand_int(&dataId);
                    rand_string(&dataInfo);
                    if (stack.push(dataId, &dataInfo)) {
                        std::cout << "pushed, id: " << dataId << "  info: " << dataInfo << std::endl;
                    } else {
                        std::cout << "Error: pushed invalid input (id: " << dataId << ", info: " << dataInfo << ") or full stack overflow" << std::endl;
                    }
                    break;
                case 4:
                    //isEmpty case
                    if (stack.isEmpty()) {
                        std::cout << "stack is empty" << std::endl;
                    } else {
                        std::cout << "stack is not empty" << std::endl;
                    }
                    break;
            }
        }

        } else {
        //input was not valid
        std::cout << "Error: Invalid Input" << std::endl;
        std::cout << "To use this program, include 1 and only 1 argument after the application name" << std::endl;
        std::cout << "This argument must be an integer." << std::endl;
    }

    return 0;
}

/*********************
Name: Kaden Misenheimer
Assignment 4: Int Stack
Purpose: This file is for testing the stack class, it contains mutliple different tests of the data type and prints out results
**********************/
#include "main.h"

int main(int argc, char** argv) {

    //TEST 1
    std::cout << "Test 1: Correct Input" << std::endl;
    try {
        Stack s1;
        std::cout << s1.push(10) << std::endl;
        std::cout << s1.push(20) << std::endl;
        std::cout << s1.peek() << std::endl;
        std::cout << s1.pop() << std::endl;
        std::cout << s1.pop() << std::endl;
    }
    catch (int x) {
        std::cout << "Error" << std::endl;
    }
    std::cout << std::endl;

    //TEST 2
    std::cout << "Test 2: Underflow" << std::endl;
    try {
        Stack s2;
        std::cout << s2.push(10) << std::endl;
        std::cout << s2.push(20) << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl; //one more pop than push, tries to pop an empty stack, results in error
    }
    catch (int x) {
        std::cout << "Error: Empty Stack is being popped from" << std::endl;
    }
    std::cout << std::endl;

    //TEST 3
    std::cout << "Test 3: Overflow" << std::endl;
    try {
        Stack s3;
        std::cout << s3.push(10) << std::endl;
        std::cout << s3.push(20) << std::endl;
        std::cout << s3.push(30) << std::endl;
        std::cout << s3.push(40) << std::endl;
        std::cout << s3.push(50) << std::endl;
        std::cout << s3.push(60) << std::endl; //pushes 6 files, the max size is only 5, the 6th file is not pushed successfully
        std::cout << s3.peek() << std::endl; //demonstrates that 50 was the last item pushed
    }
    catch (int x) {
        std::cout << "Error" << std::endl;
    }
    std::cout << std::endl;

    //TEST 4
    std::cout << "Test 4: Random Combinations" << std::endl;
    try {
        Stack s4;
        std::cout << s4.isEmpty() << std::endl; //use of isEmpty
        std::cout << s4.push(10) << std::endl; //use of push
        std::cout << s4.push(20) << std::endl;
        std::cout << s4.push(30) << std::endl;
        std::cout << s4.peek() << std::endl; //use of peek
        std::cout << s4.push(40) << std::endl;
        std::cout << s4.isEmpty() << std::endl; //use of isEmpty
        std::cout << s4.pop() << std::endl; //use of pop
        std::cout << s4.pop() << std::endl;
        std::cout << s4.pop() << std::endl;
        std::cout << s4.pop() << std::endl;
        std::cout << s4.isEmpty() << std::endl;

    }
    catch (int x) {
        std::cout << "Error" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
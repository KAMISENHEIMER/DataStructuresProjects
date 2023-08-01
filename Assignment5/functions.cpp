/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}

void rand_int(int *num){
    //picks a number between 1 and MAXINTSIZE, this will be how many digits the number has
    int intLength = (rand() % MAXINTSIZE) + 1;

    //determines the largest possible number for intLength amount of digits (+1).
    int maxsize = pow(10,intLength);

    //sets num to a random int size 0 to maxsize-1
    *num = rand() % maxsize;

    return;
}

//determines if a string is a number or not
bool isNumber(std::string str) {
    bool success = true;

    //checks if string starts with - and has at least 2 digits (for negatives)
    if (str.length() >= 2 && str[0] == '-')
    {
        for (int i = 1; i< str.length(); i++) {
            if (!isdigit(str[i])) {
                success = false;    //as soon as a non number is found success is set to be false;
            }
        }
    } else {
        for (int i = 0; i< str.length(); i++) {
            if (!isdigit(str[i])) {
                success = false;
            }
        }
    }

    return success;
}

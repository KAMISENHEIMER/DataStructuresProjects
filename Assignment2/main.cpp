/*********************
Name: Kaden Misenheimer
Assignment 2: Hello World
Purpose: This program prints the amount and length of command line arguments when the program is run.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    cout << "My Command line analyzer..." << endl;
    cout << "The number of command line parameters are: " << argc << endl;
    std::cout << "The length of the name of the program is: " << string_length(argv[0]) << std::endl;

    //starts at 1 (the second parameter)

    //for loop loops through all parameters. does not enter loop if there is only 1 parameter
    for (int i = 1; i < argc; i++) {
        std::cout << "The length of parameter " << i << " is " << string_length(argv[i]) << std::endl;

    }

    return 0;
}

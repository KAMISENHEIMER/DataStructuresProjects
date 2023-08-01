/*********************
Name: Kaden Misenheimer
Assignment 2: Hello World
Purpose: This file holds any functions to be used in the project.
**********************/
#include "functions.h"

//returns the length of the string passed into it
int string_length(const char *str) {
    int i = 0;
    //while the string character is not the null character (end of the string) add 1 to the count
    while (str[i]!='\0') {
        i++;
    }
    return i;
}
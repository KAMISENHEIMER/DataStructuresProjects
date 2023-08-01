/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACKS_FUNCTIONS_H
#define STACKS_FUNCTIONS_H

#define MAXSTRSIZE 8
#define MAXINTSIZE 8


#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time */
#include <string>     /* string */
#include <cmath>      /* math */

void rand_string(std::string*);

void rand_int(int*);

bool isNumber(std::string);

#endif /* STACKS_FUNCTIONS_H */
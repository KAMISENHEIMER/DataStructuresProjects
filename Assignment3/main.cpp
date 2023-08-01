/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This program creates sword objects and prints info about them.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    //creates a sword object with no parameters
    Sword mySword1;
    Sword mySword2("Iron Dagger", 3, 45);

    MagicSword myMagicSword1;
    MagicSword myMagicSword2("Excaliber", 50, 100, 25, "fire");

    displaySword(&mySword1);
    displaySword(&mySword2);

    displayMagicSword(&myMagicSword1);
    displayMagicSword(&myMagicSword2);

    return 0;
}

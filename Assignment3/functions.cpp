/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This file contains important functions to be used in the file.
**********************/

#include "functions.h"

void displaySword(Sword *mySword) {
    std::cout << mySword->getName() << std::endl;
    std::cout << mySword->getDamage() << " damage" << std::endl;
    std::cout << mySword->getDurability() << " durability" << std::endl;
    std::cout << std::endl;
}

void displayMagicSword(MagicSword *myMagicSword) {
    std::cout << myMagicSword->getName() << std::endl;
    std::cout << myMagicSword->getDamage() << " damage" << std::endl;
    std::cout << myMagicSword->getDurability() << " durability" << std::endl;
    std::cout << myMagicSword->getExtraDamage() << " extra " << myMagicSword->getDamageType() << " damage" << std::endl;
    std::cout << std::endl;
}
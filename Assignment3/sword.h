/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This is the header file for the sword.cpp file.
**********************/

#ifndef ASSIGNMENT3_SWORD_H
#define ASSIGNMENT3_SWORD_H

#include <string> //was not 100% sure where to add this include, but as includes and headers eventually led back to the sword.h file, it seemed to be a good fit.

//the lowest damage and durability a sword can have is 1, value will be used for protectors.
#define MIN 1

class Sword {
public:
    //constructors
    Sword();
    Sword(std::string, int, int);

    //getters
    std::string getName();
    int getDamage();
    int getDurability();

    //setters
    void setName(std::string);
    void setDamage(int);
    void setDurability(int);

protected:
    //private variables that hold info on the sword
    std::string name;
    int damage, durability;

};


#endif //ASSIGNMENT3_SWORD_H

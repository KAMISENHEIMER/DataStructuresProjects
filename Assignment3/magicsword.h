/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This is the header file for the magicsword.cpp file.
**********************/

#ifndef ASSIGNMENT3_MAGICSWORD_H
#define ASSIGNMENT3_MAGICSWORD_H

#include "sword.h"

class MagicSword : public Sword {
public:
    //constructors
    MagicSword();
    MagicSword(std::string, int, int, int, std::string);

    //getters
    int getExtraDamage();
    std::string getDamageType();


    //setters
    void setDurability(int); //Sword method being overridden
    void setExtraDamage(int);
    void setDamageType(std::string);

private:
    int extraDamage;
    std::string damageType;
};

#endif //ASSIGNMENT3_MAGICSWORD_H

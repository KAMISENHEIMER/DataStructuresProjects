/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This is the class for the magicsword object. It inherits sword, and contains the constructor and the get and set methods for the magicsword.
**********************/

#include "magicsword.h"

//constructors
MagicSword::MagicSword() {
    setName("Magic Stick");
    setDamage(MIN);
    setDurability(MIN);
    setExtraDamage(MIN);
    setDamageType("magic");
}

MagicSword::MagicSword(std::string n, int da, int du, int extra, std::string type) {
    setName(n);
    setDamage(da);
    setDurability(du);
    setExtraDamage(extra);
    setDamageType(type);
}

//getters
int MagicSword::getExtraDamage() {
    return extraDamage;
}
std::string MagicSword::getDamageType() {
    return damageType;
}

//setters
void MagicSword::setDurability(int du) {
    //magic swords have 10 times the normal amount of normal durability. (This overrides the Sword method).
    if (du > MIN) {
        durability = du * 10;
    } else {
        durability = MIN * 10;
    }
}
void MagicSword::setExtraDamage(int extra) {
    if (extra > MIN) {
        extraDamage = extra;
    } else {
        extraDamage = MIN;
    }
}
void MagicSword::setDamageType(std::string type) {
    damageType = type;
}
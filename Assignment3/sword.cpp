/*********************
Name: Kaden Misenheimer
Assignment 3: Classes and Objects
Purpose: This is the class for the sword object. It contains the constructor and the get and set methods for the sword.
**********************/

#include "sword.h"

//constructors
Sword::Sword() {
    setName("Dummy Sword");
    setDamage(MIN);
    setDurability(MIN);
}

Sword::Sword(std::string n, int da, int du) {
    setName(n);
    setDamage(da);
    setDurability(du);
}

//getters
std::string Sword::getName() {
    return name;
}

int Sword::getDamage() {
    return damage;
}

int Sword::getDurability() {
    return durability;
}


//setters
void Sword::setName(std::string n) {
    name = n;
}

void Sword::setDamage(int da) {
    if (da > MIN) {
        damage = da;
    } else {
        damage = MIN;
    }
}

void Sword::setDurability(int du) {
    if (du > MIN) {
        durability = du;
    } else {
        durability = MIN;
    }
}
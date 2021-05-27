#include <iostream>
#include "Potion.h"
#include <sstream>

using namespace std;

Potion::Potion() {
    ing1 = -1;
    ing2 = -1;
    name = "empty";
    id = count++;
    isMade = false;
}

int Potion::count = 0;

Potion::Potion(int ing1, int ing2, string name, bool isMade) {
    this -> ing1 = ing1;
    this -> ing2 = ing2;
    this -> name = name;
    this -> isMade = isMade;
}

void Potion::setBaseIngredient1(int ing1) {
    if (0 <= ing1 && ing1 <= 9) {
        this -> ing1 = ing1;
    }
}

void Potion::setBaseIngredient2(int ing2) {
    if (0 <= ing2 && ing2 <= 9) {
        this -> ing2 = ing2;
    }
}

void Potion::setName(string name) {
    this -> name = name;
}

void Potion::setIsMade(bool isMade) {
    this -> isMade = isMade;
}

int Potion::getBaseIngredient1() {
    return ing1;
}

int Potion::getBaseIngredient2() {
    return ing2;
}

string Potion::getName(){
    return name;
}

bool Potion::getIsMade() {
    return isMade;
}

int Potion::getId() {
    return id;
}

string Potion::toString() {
    stringstream ss;

    ss << "name: ";
    ss << name;
    ss << "; ingredient1: ";
    ss << ing1;
    ss << "; ingredient2: ";
    ss << ing2;
    ss << "; id: ";
    ss << id;
    ss << "; has been made?: ";
    ss << isMade;

    return ss.str();
}

#include <iostream>
#ifndef POTION_H
#define POTION_H

using namespace std;

class Potion {
private:
    int ing1;
    int ing2;
    string name;
    int id;
    bool isMade;
    static int count;
public:
    Potion();
    Potion(int ing1, int ing2, string name, bool isMade);
    void setBaseIngredient1(int ing1);
    void setBaseIngredient2(int ing2);
    void setName(string name);
    void setIsMade(bool isMade);
    int getBaseIngredient1();
    int getBaseIngredient2();
    string getName();
    bool getIsMade();
    int getId();
    string toString();
}

#endif
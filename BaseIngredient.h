#include <iostream>

using namespace std;

#ifndef BASEINGREDIENT_H
#define BASEINGREDIENT_H

class BaseIngredient
{
private:
	string name;
    int id;
    static int count;

public:
	BaseIngredient();
    BaseIngredient(string, int);
    string setName();
    int setId();
    int getId();
    string getName();

};

#endif
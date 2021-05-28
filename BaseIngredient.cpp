#include "BaseIngredient.h"
#include <sstream>


BaseIngredient::BaseIngredient()
{
    name = "Joe";

}

int BaseIngredient::count = 0;

BaseIngredient::BaseIngredient(string n)
{
    name = n;
    id = count++;
}

void BaseIngredient::setName(string n) {
	name = n;
}

int BaseIngredient::getId()
{
    return id;
}

string BaseIngredient::getName()
{
    return name;
}

string BaseIngredient::toString() {
    stringstream ss;

    ss << "name: ";
    ss << name;
    ss << "; id: ";
    ss << id;

    return ss.str();
}
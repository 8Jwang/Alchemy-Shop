#include "BaseIngredient.h"

BaseIngredient::BaseIngredient()
{
    name = "Joe";
    id = count++;

}

int BaseIngredient::count = 0;

BaseIngredient::BaseIngredient(string n)
{
    name = n;
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
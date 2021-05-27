#include "BaseIngredient.h"

BaseIngredient::BaseIngredient()
{
    name = "Joe";
    id = 0;
    private:
        static int count;
}

int BaseIngredient::count = 0;

BaseIngredient(string n, int i)
{
    setName(n);
    setId(i);
}

void BaseIngredient::setName(string n) {
	name = n;
}

void BaseIngredient::setId(int i) {
	id = i;
}

int BaseIngredient::getId()
{
    return id;
}

string BaseIngredient::getName()
{
    return name;
}
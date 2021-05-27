//// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"
#include <iostream>
using namespace std;

void baseIngredientTest()
{
    BaseIngredient b0("Life");
    BaseIngredient b1("Death");
    BaseIngredient b2("Wood");
    BaseIngredient b3("Water");
    BaseIngredient b4("Fire");
    BaseIngredient b5("Love");
    BaseIngredient b6("Electricity");
    BaseIngredient b7("Air");
    BaseIngredient b8("Cupcake");
    BaseIngredient b9("Toothbrush");
}

void potionTest() {
    Potion p1(0, 1, "testinggg", false);
    Potion p2(1, 2, "testinggg2", false);
    p1.setBaseIngredient1(3);
    p1.setBaseIngredient1(90);
    cout << p1.toString() << endl;
    cout << p2.toString() << endl;
}

int main() {
    Customer c1;
    Customer c2("Dude", "613-123-4566", 2, true);
    Customer c3("Name", "1234567-8999", 10, false);
    cout << c1.toString() << endl;
    cout << c2.toString() << endl;
    cout << c3.toString() << endl;
    string ph = "111-111-1111";
    c3.setPhone(ph);
    cout << c3.getPhone() << endl;
    cout << "hello" << endl;

    return 0;
}
//// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"
#include <iostream>
#include <time.h>
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

void genCustomers() {
    int random = rand() % 10;
    Customer c0("Bob", "613-598-1283", random, false);
    Customer c1("Sam", "123-456-7891", random, false);
    Customer c2();
    Customer c3();
    Customer c4();
    Customer c5();
    Customer c6();
    Customer c7();
    Customer c8();
    Customer c9();





}

int main() {
    srand(time(0));

    //potionTest();

    return 0;
}
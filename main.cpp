// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"

using namespace std;

void baseIngredientTest()
{
    BaseIngredient b1("Life", 0);
    BaseIngredient b1("Death", 1);
    BaseIngredient b1("Wood", 2);
    BaseIngredient b1("Water", 3);
    BaseIngredient b1("Fire", 4);
    BaseIngredient b1("Love", 5);
    BaseIngredient b1("Electricity", 6);
    BaseIngredient b1("Air", 7);
    BaseIngredient b1("Cupcake", 8);
    BaseIngredient b1("Toothbrush", 9);
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
    
    return 0;
}
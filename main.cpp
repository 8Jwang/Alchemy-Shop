// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"

using namespace std;

void baseIngredientTest()
{
    BaseIngredient b0("Life", 0);
    BaseIngredient b1("Death", 1);
    BaseIngredient b2("Wood", 2);
    BaseIngredient b3("Water", 3);
    BaseIngredient b4("Fire", 4);
    BaseIngredient b5("Love", 5);
    BaseIngredient b6("Electricity", 6);
    BaseIngredient b7("Air", 7);
    BaseIngredient b8("Cupcake", 8);
    BaseIngredient b9("Toothbrush", 9);
    cout << b0.getName() << endl;
    cout << b0.getId() << endl;
    cout << b1.getName() << endl;
    cout << b1.getId() << endl;
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
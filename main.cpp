//// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"
#include <iostream>
#include <time.h>
using namespace std;

// functions that generate and returns the array
Customer * genCustomers(Customer customerList[]) {
    Customer c0("Bob", "333-666-9999", rand() % 10, false);
    Customer c1("Arys Borderlands", "123-456-7891", rand() % 10, false);
    Customer c2("Chibueze Teaman", "545-777-6868", rand() % 10, false);
    Customer c3("Chromium Steele", "242-424-2424", rand() % 10, false);
    Customer c4("Alfredo Linguini Gusteau", "613-232-4444", rand() % 10, false);
    Customer c5("Maurice Shoob", "676-937-3829", rand() % 10, false);
    Customer c6("Cruella de Vil", "437-234-5948", rand() % 10, false);
    Customer c7("Ambrosia Wonton", "816-908-0000", rand() % 10, false);
    Customer c8("Demi Burgeress", "169-242-7092", rand() % 10, false);
    Customer c9("Fatimah Sweeney", "666-666-1004", rand() % 10, false);

    customerList[0] = c0;
    customerList[1] = c1;
    customerList[2] = c2;
    customerList[3] = c3;
    customerList[4] = c4;
    customerList[5] = c5;
    customerList[6] = c6;
    customerList[7] = c7;
    customerList[8] = c8;
    customerList[9] = c9;

    return customerList;
}

Potion * genPotions(Potion potionList[]) {
    Potion p0(0, 3, "Fish potion", false);
    Potion p1(0, 1, "Aging potion", false);
    Potion p2(1, 8, "Poison potion", false);
    Potion p3(2, 4, "Arson potion", false);
    Potion p4(2, 7, "Knockout potion", false);
    Potion p5(3, 9, "Clean teeth potion", false);
    Potion p6(4, 8, "Eternal hunger potion", false);
    Potion p7(5, 6, "Computer science skills potion", false);
    Potion p8(5, 7, "Levitation potion", false);
    Potion p9(6, 9, "Auto-scrubbing potion", false);

    potionList[0] = p0;
    potionList[1] = p1;
    potionList[2] = p2;
    potionList[3] = p3;
    potionList[4] = p4;
    potionList[5] = p5;
    potionList[6] = p6;
    potionList[7] = p7;
    potionList[8] = p8;
    potionList[9] = p9;

    return potionList;
}

BaseIngredient * genBaseIngredients(BaseIngredient baseIngredientList[]) {
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

    baseIngredientList[0] = b0;
    baseIngredientList[1] = b1;
    baseIngredientList[2] = b2;
    baseIngredientList[3] = b3;
    baseIngredientList[4] = b4;
    baseIngredientList[5] = b5;
    baseIngredientList[6] = b6;
    baseIngredientList[7] = b7;
    baseIngredientList[8] = b8;
    baseIngredientList[9] = b9;

    return baseIngredientList;

}

int main() {
    srand(time(0));

    // initializing arrays
    Customer customerList[10];
    BaseIngredient baseIngredientList[10];
    Potion potionList[10];

    // running the functions
    genCustomers(customerList);
    genBaseIngredients(baseIngredientList);
    genPotions(potionList);

    //getting three different customers
    Customer customerOrderingList[3];
    int available[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //checking if customer is already in the queue
    for(int i = 0; i < 3; i++) {
        int x;
        int y;
        do {
            y = rand() % 10;
            x = available[y];
            available[y] = -1;
        } while (x == -1);

        customerOrderingList[i] = customerList[x];
        cout << customerOrderingList[i].toString() << endl;
    }

    //listing potions and ingredients
    cout << "Potions: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << potionList[i].toString() << endl;
    }

    cout << "Base Ingredients: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << baseIngredientList[i].toString() << endl;
    }

    //potionTest();

    return 0;
}
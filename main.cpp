//// DO WE NEED DESTRUCTORS??? POINTERS?? TT
#include "Potion.h"
#include "BaseIngredient.h"
#include "Customer.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <string.h>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

using namespace std;

// functions that generate and returns the array
// todo: do we uh... need to delete and like reallocate space or?
Customer *genCustomers(Customer customerList[]) {
    Customer c0("Bob", "333-666-9999", rand() % 10, false, false);
    Customer c1("Arys Borderlands", "123-456-7891", rand() % 10, false, false);
    Customer c2("Chibueze Teaman", "545-777-6868", rand() % 10, false, false);
    Customer c3("Chromium Steele", "242-424-2424", rand() % 10, false, false);
    Customer c4("Alfredo Linguini Gusteau", "613-232-4444", rand() % 10, false, false);
    Customer c5("Maurice Shoob", "676-937-3829", rand() % 10, false, false);
    Customer c6("Cruella de Vil", "437-234-5948", rand() % 10, false, false);
    Customer c7("Ambrosia Wonton", "816-908-0000", rand() % 10, false, false);
    Customer c8("Demi Burgeress", "169-242-7092", rand() % 10, false, false);
    Customer c9("Fatimah Sweeney", "666-666-1004", rand() % 10, false, false);

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

Potion *genPotions(Potion potionList[]) {
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

BaseIngredient *genBaseIngredients(BaseIngredient baseIngredientList[]) {
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

//saving the game
void savingInformation(int points, Customer customerOrderingList[]) {
    ofstream MyFile("saveGame.txt");
    // include customers currently in queue and total points
    for (int i = 0; i < 3; i++) {
        MyFile << customerOrderingList[i].getName() << "\n";
        MyFile << customerOrderingList[i].getPhone() << "\n";
        MyFile << customerOrderingList[i].getRequest() << "\n";
        MyFile << customerOrderingList[i].getId() << "\n";
    }
    MyFile << points << "\n";
    MyFile.close();
}

//list of past customers
void flex(Customer customerOrderingList[], int index) {
    ofstream outfile;
    outfile.open("flexList.txt", ios_base::app);
    outfile << customerOrderingList[index].getName() << "\n";
    outfile << customerOrderingList[index].getPhone() << "\n";
    outfile << customerOrderingList[index].getRequest() << "\n";
    outfile << customerOrderingList[index].getIsMad() << "\n";
    outfile << "\n";
}

int countLines() {
    //initializing variables
    int numLines = 0;
    string line;
    ifstream myFile("flexList.txt");
    //counting number of lines
    while (getline(myFile, line)) {
        ++numLines;
    }
    return numLines;
}

//replacing customer queue with saved information
int getInformation(Customer customerOrderingList[], int points, int available[]) {
    string tempArray[13];
    //resetting availability list in order to replace customer queue
    for (int i = 0; i < 10; i++) {
        available[i] = i;
    }
    int count = 0;
    string myText;
    //retrieving saved information from last save and quit
    ifstream MyReadFile("saveGame.txt");
    while (getline(MyReadFile, myText)) {
        tempArray[count] = myText;
        count++;
    }
    //replacing existing customer queue with saved information
    for (int i = 0; i < 3; i++) {
        customerOrderingList[i].setName(tempArray[((3 * i) + i)]);
        customerOrderingList[i].setPhone(tempArray[((3 * i) + i) + 1]);
        customerOrderingList[i].setRequest(stoi(tempArray[((3 * i) + i) + 2]));
        customerOrderingList[i].setId(stoi(tempArray[((3 * i) + i) + 3]));
        available[stoi(tempArray[((3 * i) + i) + 3])] = -1;
    }
    //replacing existing points with saved points
    points = stoi(tempArray[12]);
    return points;
}

string **getFlexList() {
    // creating a 2D array
    string **matrix;
    int numCustomers = countLines() / 5;
    matrix = new string *[numCustomers];
    for (int i = 0; i < numCustomers; i++) {
        matrix[i] = new string[5];
    }

    // putting all lines from flex list into temp array
    string tempArray[numCustomers * 5];
    string line;
    ifstream myFile("flexList.txt");
    int count1 = 0;
    int count2 = 0;
    while (getline(myFile, line)) {
        tempArray[count1] = line;
        count1++;
    }

    // moving all values from tempArray to matrix (a 2d array)
    for (int i = 0; i < numCustomers; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = tempArray[count2];
            count2++;
        }
    }
    return matrix;
}

//sorting flex list alphabetically
void selectSort(string **arr, int length) {
    int pos_max;
    string temp[5];

    for (int i = length - 1; i > 0; i--) {
        //setting first index as temporary largest position
        pos_max = 0;
        for (int j = 1; j <= i; j++) {
            //checks if current position is greater alphabetically
            if (strcmp(arr[j][0].c_str(), arr[pos_max][0].c_str()) < 0) {

                pos_max = j; //if larger found, set new largest
            }
        }
        //swapping element at i (and all the elements that are associated with it in 2d list) with largest element in unsorted section
        for (int k = 0; k < 5; k++) {

            temp[k] = arr[i][k];
            arr[i][k] = arr[pos_max][k];
            arr[pos_max][k] = temp[k];
        }

    }
    //outputting order
    for (int i = length - 1; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << endl;
        }
    }
}

//checks if ingredients combine to make potion (and what potion)
int makePotion(int ingredient1, int ingredient2, Potion potionList[]) {
    for (int i = 0; i < 10; i++) {
        if ((ingredient1 == potionList[i].getBaseIngredient1() && ingredient2 == potionList[i].getBaseIngredient2()) ||
            (ingredient1 == potionList[i].getBaseIngredient2() && ingredient2 == potionList[i].getBaseIngredient1())) {
            return potionList[i].getId();
        }
    }
    return -1;
}

//checks if potion made is the right potion that the customer ordered
int giveCustomer(int potion, int customer, Customer customerOrderingList[], int points) {
    //if the potion the customer ordered is the potion delivered, increase the points and set isMade to true
    if (customerOrderingList[customer].getRequest() == potion) {
        cout << "you have successfully given the potion to the customer!" << endl;
        customerOrderingList[customer].setIsMade(true);
        points++;
        cout << "You now have " << points << " points!" << endl;
        //if the potion the customer ordered is not the potion delivered, decrease the points and set isMad to true
    } else {
        cout << "The customer was unhappy with the potion they received. You lost 1 point." << endl;
        customerOrderingList[customer].setIsMad(true);
        points--;
        cout << "You now have " << points << " points!" << endl;
    }
    //update the flex list
    flex(customerOrderingList, customer);

    return points;
}

// updating the customer ordering list after a customer leaves
Customer *updateCustomerOrderingList(Customer customerOrderingList[], Customer customerList[], int available[]) {
    for (int i = 0; i < 3; i++) {
        int temp;
        if (customerOrderingList[i].getIsMad() == true || customerOrderingList[i].getIsMade() == true) {

            int x;
            int y;
            //loops until index of available customer is randomly selected
            do {
                //random index is selected
                y = rand() % 10;
                //id of customer at that index is taken from availability list
                x = available[y];
                //availability list at index is set to -1 (customer is not available)
                available[y] = -1;
            } while (x == -1);

            //resets customer status
            customerOrderingList[i].setIsMade(false);
            customerOrderingList[i].setIsMad(false);

            //setting temp to the id of the customer that just left
            temp = customerOrderingList[i].getId();

            //a customer from customerList is selected and put into customerOrderingList
            customerOrderingList[i] = customerList[x];

            // after customer leaves, customer becomes available
            available[temp] = temp;

            cout << "A new customer arrived! Here is your customer list: " << endl;
            for (int i = 0; i < 3; i++) {
                cout << i << ". " << customerOrderingList[i].toString() << endl;
            }

//            for (int i = 0; i < 10; i++) {
//                cout << available[i] << " ";
//            }

        }
    }

    return customerOrderingList;
}

// placing customers from the customer list into the ordering list
Customer *generateCustomerOrderingList(Customer customerOrderingList[], Customer customerList[], int available[]) {
    //same as above, rng generator that catches if a customer is already in queue
    for (int i = 0; i < 3; i++) {
        int x;
        int y;
        do {
            y = rand() % 10;
            x = available[y];
            available[y] = -1;
        } while (x == -1);

        customerOrderingList[i] = customerList[x];
        cout << i << ". " << customerOrderingList[i].toString() << endl;
    }
    return customerOrderingList;
}

//outputting flex list at end of game
void outputResults() {
    string results;
    ifstream MyReadFile("flexList.txt");
    while (getline(MyReadFile, results)) {
        cout << results << endl;
    }
    MyReadFile.close();
}

//clear contents of flex list
void delFlexList() {
    fstream ofs;
    ofs.open("flexList.txt", ios::out | ios::trunc);
    ofs.close();
}

//clear contents of save game
void delSaveGame() {
    fstream ofs;
    ofs.open("saveGame.txt", ios::out | ios::trunc);
    ofs.close();
}

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(rect);

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    srand(time(0));

    int points = 3;


    // initializing arrays
    Customer customerList[10];
    BaseIngredient baseIngredientList[10];
    Potion potionList[10];

    // running the functions that generate customers, ingredients, potions
    genCustomers(customerList);
    genBaseIngredients(baseIngredientList);
    genPotions(potionList);

    //getting three different customers
    Customer customerOrderingList[3];
    int available[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ifstream read("saveGame.txt");

    if (!read) return 0;
    bool empty = read.peek() == EOF;

    string reload;

    //generating and outputting customer queue
    if (!empty) {
        cout << "If you would like to reload your saved game, type 'reload'! If not, enter any letter!" << endl;
        cin >> reload;
        if (reload == "reload") {
            points = getInformation(customerOrderingList, points, available);
            for (int i = 0; i < 3; i++) {
                cout << i << ". " << customerOrderingList[i].toString() << endl;
            }
            cout << "Current points: " << points << endl;

        } else {
            delFlexList();
            delSaveGame();
            generateCustomerOrderingList(customerOrderingList, customerList, available);
        }
    } else {
        generateCustomerOrderingList(customerOrderingList, customerList, available);
    }
    cout << "hello" << endl;

    int ingredient1;
    int ingredient2;
    int myPotion;
    string quit = "continue";
    do {
        cout << "pls pick two ingredients" << endl;
        cin >> ingredient1 >> ingredient2;
        cout << ingredient1 << " " << ingredient2 << endl;
        myPotion = makePotion(ingredient1, ingredient2, potionList);
        if (myPotion == -1) {
            cout << "Your combination did not make a potion! Workspace has been reset" << endl;
            continue;
        } else {
            int customer;
            cout << "You made potion #" << myPotion
                 << "! If you'd like to trash this potion, please enter '-1'. Otherwise, please enter which customer you'd like to give it to (0, 1 or 2)."
                 << endl;
            cin >> customer;
            if (customer == -1) {
                continue;
            } else {
                points = giveCustomer(myPotion, customer, customerOrderingList, points);
                if (points != 0 && points != 10) {
                    updateCustomerOrderingList(customerOrderingList, customerList, available);
                    savingInformation(points, customerOrderingList);
                    cout << "If you would like to quit and save, type 'quit'. Otherwise, enter anything!" << endl;
                    cin >> quit;
                }

            }
        }

    } while (points > 0 && points < 10 && quit != "quit");

    string **flexListArray = getFlexList();
    int num = countLines() / 5;

    if (points == 0) {
        cout << "Sorry, you ran out of points. Better luck next time!" << endl;
        delSaveGame();

        cout
                << "If you'd like to sort your flex list chronologically, enter 1. If you'd like to sort it alphabetically, enter 2."
                << endl;
        int sortNum;
        cin >> sortNum;
        cout << "Here is your list of past customers: " << endl;
        if (sortNum == 1) {
            outputResults();

        } else if (sortNum == 2) {
            selectSort(flexListArray, num);
        }
        delFlexList();


        //returns the user to the title screen
    } else if (points == 10) {
        cout << "Great job! Your alchemy shop has a stellar reputation. You win!" << endl;
        delSaveGame();
        cout
                << "If you'd like to sort your flex list chronologically, enter 1. If you'd like to sort it alphabetically, enter 2."
                << endl;
        int sortNum;
        cin >> sortNum;
        cout << "Here is your list of past customers: " << endl;
        if (sortNum == 1) {
            outputResults();

        } else if (sortNum == 2) {
            selectSort(flexListArray, num);
        }
        delFlexList();

        //returns the user to the title screen
    } else {
        cout << "Your game has been saved!" << endl;
    }

    //deallocating each pointing within the pointer array
    for (int i = 0; i < num; i++) {
        delete[] flexListArray[i];
    }
    delete[] flexListArray; //deallocating the pointer

    return a.exec();
    //return 0;
}
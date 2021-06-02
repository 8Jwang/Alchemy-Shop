#include <iostream>
#include <string>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
	string name;
	string phone;
	int request;
	int id;
	bool isMad;
	bool isMade;
	static int count;

public:
	Customer();
	Customer(string, string, int, bool, bool);
	string getName();
	string getPhone();
	int getRequest();
	bool getIsMad();
	int getId();
	void setName(string);
	void setPhone(string);
    void setIsMade(bool isMade);
    void setRequest(int);
	void setIsMad(bool);
    bool getIsMade();
    void setId(int);
	string toString();
};

#endif
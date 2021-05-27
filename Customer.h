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
	bool isMad;

public:
	Customer();
	Customer(string, int, int, bool);
	string getName();
	int getPhone();
	int getRequest();
	bool getIsMad();
	void setName(string);
	void setPhone(string);
	void setRequest(int);
	void setIsMad(bool);
	string toString();
};

#endif
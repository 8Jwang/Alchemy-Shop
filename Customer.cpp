#include "Customer.h"
#include <sstream>

Customer::Customer() {
	name = "Bob";
	phone = "000-000-0000";
	request = 0;
	isMad = false;
	isMade = false;
}
int Customer::count = 0;

Customer::Customer(string n, string p, int r, bool m, bool me) {
	setName(n);
	setPhone(p);
	setRequest(r);
	setIsMad(m);
	setIsMade(me);
	id = count++;
}

string Customer::getName() {
	return name;
}

string Customer::getPhone() {
	return phone;
}

int Customer::getRequest() {
	return request;
}

bool Customer::getIsMad() {
	return isMad;
}

bool Customer::getIsMade() {
    return isMade;
}

int Customer::getId() {
    return id;
}

void Customer::setName(string n) {
	name = n;
}

void Customer::setPhone(string p) {
	if (p.length() == 12 && p[3] == '-' && p[7] == '-') {
		phone = p;
	}
	else {
		phone = "000-000-0000";
	}
}

void Customer::setRequest(int r) {
	if (0 <= r && r <= 9) {
		request = r;
	}
	else {
		request = 0;
	}
}

void Customer::setIsMad(bool m) {
	isMad = m;
}

void Customer::setIsMade(bool isMade) {
    this -> isMade = isMade;
}

void Customer::setId(int i) {
    id = i;
}

string Customer::toString() {
    stringstream ss;

    ss << name;
    ss << " requests order # ";
    ss << request;
    ss << " (contact at ";
    ss << phone;
    ss << ")";


    return ss.str();
}
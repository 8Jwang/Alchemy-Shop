#include "Customer.h"

Customer::Customer() {
	name = "Bob";
	phone = "000-000-0000";
	request = 0;
	isMad = false;
}

Customer::Customer(string n, string p, int r, bool m) {
	setName(n);
	setPhone(p);
	setRequest(r);
	setIsMad(m);
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

//
//string Customer::toString() {
//	return name + " requests order #" + request + " (contact at " + phone + ")";
//}
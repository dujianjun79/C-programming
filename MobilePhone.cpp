#include "MobilePhone.h"

MobilePhone::MobilePhone()
{
	TelephoneNumber = "000-000-0000";
	RingTone = "Ring!";
	next = NULL;
}

MobilePhone::MobilePhone(string number) { //This constructor is used store the inputed phone number.
	TelephoneNumber = number;
	RingTone = "Ring!";
	next = NULL;
}

MobilePhone::~MobilePhone()
{
}

void MobilePhone::ShowNumber() {
	cout << TelephoneNumber<<" :"; 
}

void MobilePhone::Ring() {
	cout << TelephoneNumber << " :";
	for (int i = 0; i < 5; i++) {
		cout << RingTone << " ";
	}
	cout << endl;
}
#include "GooglePhone.h"

GooglePhone::GooglePhone(string n)
{
	RingTone = "Beep!";
	TelephoneNumber = n;
	next = NULL;
	cout << "This is google phone" << endl;
}

GooglePhone::~GooglePhone()
{
}

void GooglePhone::Ring() {
	cout << TelephoneNumber << " :";
	for(int i=0;i<3;i++){
	cout << RingTone << " ";
	}
	cout << endl;
}

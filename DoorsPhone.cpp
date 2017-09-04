#include "DoorsPhone.h"

DoorsPhone::DoorsPhone(string n)
{
	RingTone = "brt!";
	TelephoneNumber = n;
	next = NULL;
}

DoorsPhone::~DoorsPhone()
{
}

void DoorsPhone::Ring() {
	cout << TelephoneNumber << " :";
	for (int i = 0; i < 7; i++) {
		cout << RingTone << " ";
	}
	cout << endl;
}
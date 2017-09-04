#include "RobotPhone.h"

RobotPhone::RobotPhone(string n)
{
	RingTone = "Go!Go!Ro!Bot!Phone!";
	TelephoneNumber = n;
	next = NULL;
}


RobotPhone::~RobotPhone()
{
}

void RobotPhone::Ring() {
	cout << TelephoneNumber << " :";
	cout << RingTone << " " << endl;
}
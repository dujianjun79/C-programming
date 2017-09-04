#include "LinkedList.h"
#include "MobilePhone.h"
#include "GooglePhone.h"
#include "DoorsPhone.h"
#include "RobotPhone.h"
#include <iostream>
#include <string>
using namespace std;

void menu(); // main menu
void shownames(); //show stduents information
void addphone(LinkedList *phonelist); //function to add a phone to the linkedlist

int main() {
	menu();
	return 0;
}

void shownames() {
	cout << "Weihua Yang, Xun Liu, Dongfang Zhang, Jianjun Du" << endl;
	cout << "CS 5303, Homework #5" << endl;
	cout << "Date: 11/18/2016" << endl;
	cout << "----------------------------------------------------" << endl;
}

void menu() {
	LinkedList phonelist;
	char choice = '\n';
	bool done = false;
	while (!done) {
		cout << "1 Show Names" << endl;
		cout << "2 Add a phone" << endl;
		cout << "3 Traverse" << endl;
		cout << "4 Clear" << endl;
		cout << "5 Quit" << endl;
		cout << ">>--------------";
		cout << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			shownames(); 
			break;
		case '2':
			addphone(&phonelist);
			break;
		case '3':
			phonelist.ringphone();
			break;
		case '4':
			phonelist.clear();
			break;
		case '5':
			done = true;
			break;
		}
	}
	cout << "see you next time." << endl;
}

void addphone(LinkedList *ptr) {
	cout << "Choose phone type" << endl;
	cout << "1 for Mobile Phone" << endl;
	cout << "2 for Google Phone"<<endl; 
	cout << "3 for Doors Phone" << endl;
	cout<<"4 for Robot Phone" << endl;
	int n;
	cin >> n;
	cout << "Enter the phone number with format XXX-XXX-XXXX" << endl;
	string number;
	cin >> number;
	if(1==n)
		{
			MobilePhone *phoneptr = new MobilePhone(number); //need a pointer for memory allocation
			ptr->add_phone(phoneptr);                        // a pointer for base class can point to a derived object
		}  //the pointer ptr is a pointer for the linkedlist, which is pass by reference 
	if(2==n)
		{
			MobilePhone *phoneptr=new GooglePhone(number);
			ptr->add_phone(phoneptr);
		}
	if(3==n)
		{
			MobilePhone *phoneptr=new DoorsPhone(number);
			ptr->add_phone(phoneptr);
		}
	if(4==n)
		{
			MobilePhone *phoneptr=new RobotPhone(number);
			ptr->add_phone(phoneptr);
		}
	}

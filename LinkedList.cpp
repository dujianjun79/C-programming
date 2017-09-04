#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::clear()
{
	cout << "Clearing Linked List" << endl;
	MobilePhone *ptr = NULL;
	MobilePhone *start = NULL;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	start = head;
	while (start != NULL)
	{
		ptr = start;
		start = start->next;
		free(ptr); //free all the allocated Mobile Phone objects with new in the main.cpp
	}
	head = NULL;
	tail = NULL;
}

void LinkedList::ringphone()
{
	MobilePhone *start = NULL;
	start = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (start != NULL) {
		start->Ring(); //This MobilePhone pointer can recogonize the different virtual functions.
		start = start->next;
	}
	
}

void LinkedList::add_phone(MobilePhone *val)
{
	MobilePhone * start = NULL;
	MobilePhone * newNode = val;
	start = head;
	if (start == NULL)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}


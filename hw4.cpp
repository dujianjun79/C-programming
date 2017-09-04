#include "hw4.h"

int main() {
	menu();
	return 0;
}

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacci_vector(vector<int>* a, int size) {
	for (int i = 0; i < size; i++) {
		(*a).push_back(fibonacci(i));
	}
}

void fibonacci_list(list<int>* b, int size) {
	for (int i = 0; i < size; i++) {
		(*b).push_back(fibonacci(i));
	}
}

void fibonacci_array(int c[], int size) {
	for (int i = 0; i < size; i++) {
		c[i] = fibonacci(i);
	}
}

void show_fibonacci(vector<int>* a, list<int>* b, int c[], int size) {
	cout << "vector:";
	for (int element : *a) {
		cout << element << " ";
	}
	cout << endl;
	cout << "array :";
	for (int i = 0; i < size; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	cout << "list  :";
	for (int element : *b) {
		cout << element << " ";
	}
	cout << endl;
}

void menu() {
	char choice = '\n';
	vector<int> a;
	list<int> b;
	int c[20];
	int p = 2017; double q = 32.1; string r = "It is a glorious thing to be the Pointer King!";
	PointerKing myPointer;
	while (choice != '3') {
		cout << endl;
		cout << "1 Test Containers" << endl;
		cout << "2 Test Pointers" << endl;
		cout << "3 Quit" << endl;
		cout << "---------------------";
		cout << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			fibonacci_vector(&a, 20);
			fibonacci_list(&b, 20);
			fibonacci_array(c, 20);
			show_fibonacci(&a, &b, c, 20);
			break;
		case '2':
			myPointer.show_change(&p, &q, &r);
			break;
		}
	}
	cout << "see you next time." << endl;
}

PointerKing::PointerKing() {
	int_p = NULL;
	double_p = NULL;
	char_p =NULL;
	int_p=new int{2016};
	double_p=new double{81.5};
	char_p = new string{"I am a Pointer Kiiing!"};
}

PointerKing::~PointerKing() {
	delete int_p;
	delete double_p;
	delete char_p;
}


void PointerKing::pointer_change(int* p, double* q, string* r) {
	int_p = p;
	double_p = q;
	char_p = r;
}

void PointerKing::show_table() {
	cout << "Int Pointer   : "<< *int_p << endl;
	cout << "Double Pointer: " << *double_p << endl;
	cout << "Char Pointer  : " << *char_p << endl;
	cout << "-----------------------------------"<<endl;
}

void PointerKing::show_change(int* p, double* q, string* r) {
	show_table();
	pointer_change(p, q, r);
	show_table();
}

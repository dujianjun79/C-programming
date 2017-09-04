// Student Name:jianjun Du
// University of Texas at Dallas
// Course: CS 5303.001
// Instructor: Dr. Eric Becker
// Homework #3
// October 15, 2016

#include "hw3.h"

int main(int argument_count, char ** argument_vector) {
	name_output();
	menu();
	return 0;
}

vector<int> input_file() {
	ifstream intf;
	intf.open("Dice.txt");
	int a;
	char b;
	vector<int> dice_roll{};
	if (!intf) cout << "can't open the Dice.txt" << endl; //Guard Condition, make sure document can be imported.
	while (!intf.eof()) {
		intf >> a >> b;
		dice_roll.push_back(a);
	}
	intf.close();
	cout << "import data succeed!" << endl;
	return dice_roll;
}

double total(vector<int> numbers) {
	double total = 0;
	for (int i = 0; i < numbers.size(); i++) {
		total += (double)numbers[i];
	}
	cout << "The total is " << total << endl;
	return total;
}

double average(vector<int> numbers) {
	double tal = 0;
	double avg = 0;
	tal = total(numbers);
	avg = tal / numbers.size();
	cout << "The average is " << avg << endl;
	return avg;
}

double variance(vector<int> numbers) {
	double avg = average(numbers);
	double var = 0;
	for (int i = 0; i < numbers.size(); i++) {
		var += pow((numbers[i] - avg), 2) / numbers.size();
	}
	cout << "The variance is " << var << endl;
	return var;
}

double standard_deviation(vector<int> numbers) {
	double sd = 0;
	double var = variance(numbers);
	sd = sqrt(var);
	cout << "The Standard deviation is " << sd << endl;
	return sd;
}

void output_file(vector<int> numbers) {
	cout << "please enter a name for the file, end with .txt" << endl;
	string name;
	cin >> name;
	ofstream outf;
	outf.open(name);
	if (!outf) cout << "can't write to the file " << name << endl;  //Guard Condition, make sure writing operation succeed.
	outf << "Jianjun Du" << endl;
	outf << "------------------------" << endl;
	outf << "total     :" << total(numbers) << endl;
	outf << "Average   :" << average(numbers) << endl;
	outf << "Variance  :" << variance(numbers) << endl;
	outf << "StDev     :" << standard_deviation(numbers) << endl;
	outf.close();
}

void menu() {
	char choice = '\n';
	vector<int> data = {};
	Counter myCounter;
	while (choice != '6') {
		cout << "" << endl;
		cout << "Main Menu:" << endl;
		cout << "1. Load From a File\n";
		cout << "2. Calculate the Statistics\n";
		cout << "3. Write to a File\n";
		cout << "4. Performe the Count\n";
		cout << "5. Display the Bargraph\n";
		cout << "6. Quit\n";
		cout << "----------------\n";
		cout << "Make sure import data before any other operation!" << endl;
		cout << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			data = input_file();
			break;
		case '2':
			if (data.size() == 0) cout << "please import data first" << endl; // Guard condition, make sure data is imported before any other operation.
			else standard_deviation(data);
			break;
		case '3':
			if (data.size() == 0) cout << "please import data first" << endl;
			else output_file(data);
			break;
		case '4':
			for (int i = 0; i < data.size(); i++) {
				myCounter.Increment(data[i]);
			}
			myCounter.ShowTable();
			break;
		case '5':
			bargraph(myCounter);
			break;
		}
	}
	cout << "see you next time!\n";
}

Counter::Counter() {
	for (int i = 0; i < 13; i++) {
		table.push_back(0);
	}
}

void Counter::Increment(int index) {
	table[index]++;
}

void Counter::ShowTable() {
	for (auto element : table) {
		cout << element << endl;
	}
}

void Counter::Reset() {
	for (auto element : table) {
		element = 0;
	}
}

int Counter::Normalization(int index) {
	int norm = table[index] / 1000;
	return norm;
}

void bargraph(Counter a) {
	int rowmax = 0;
	for (int i = 2; i <= 12; i++) {
		cout << i;
		cout << "|";
		rowmax = a.Normalization(i);
		for (int j = 0; j < rowmax; j++) {
			cout << "X";
		}
		cout << endl;
	}}
void name_output() {
	cout << "Student Name: Jianjun Du\n";
	cout << "Homework #3\n";
	cout << "October 15, 2016\n";
	cout << "--------------------\n";
}

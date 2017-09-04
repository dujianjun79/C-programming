// Student Name:jianjun Du
// University of Texas at Dallas
// Course: CS 5303.001
// Instructor: Dr. Eric Becker
// Homework #2
// September 20, 2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<double> input_vector() {
	cout << "Enter one or more floating point numbers\n";
	cout << "When you finish, please enter q for exit\n";
	string s = "";
	vector<double> numbers = {};
	double temp = 0;
	cin >> s;
	while (s[0] != 'q') {
		temp = stod(s);
		numbers.push_back(temp);
		cin >> s;
	}
	return numbers;
}

void show_vector(vector<double> numbers) {
	for (auto const n : numbers) {
		cout << n << "\n";
	}
}

void find_min(vector<double> numbers) {
	double min = 1000000.00;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < min) min = numbers[i];
	}
	cout << "The minimum is " << min << endl;
}

void find_max(vector<double> numbers) {
	double max = -1000000.00;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] > max) max = numbers[i];
	}
	cout << "The maximum is " << max << endl;
}

double total(vector<double> numbers) {
	double total = 0;
	for (int i = 0; i < numbers.size(); i++) {
		total += numbers[i];
	}
	cout << "The total is " << total << endl;
	return total;
}

double average(vector<double> numbers) {
	double tal = 0;
	double avg = 0;
	tal = total(numbers);
	avg = tal / numbers.size();
	cout << "The average is " << avg << endl;
	return avg;
}

double variance(vector<double> numbers) {
	double avg = average(numbers);
	double var = 0;
	for (int i = 0; i < numbers.size(); i++) {
		var += pow((numbers[i] - avg), 2) / numbers.size();
	}
	cout << "The variance is " << var << endl;
	return var;
}

void standard_deviation(vector<double> numbers) {
	double sd = 0;
	double var = variance(numbers);
	sd = sqrt(var);
	cout << "The standard deviation is " << sd << endl;
}

void name_output() {
	cout << "Student Name: Jianjun Du\n";
	cout << "Homework #2\n";
	cout << "September 20, 2016\n";
	cout << "--------------------\n";
}

void function() {
	char choice='\n';
	vector<double> data = {};
	while (choice != '9') {
		cout << "" << endl;
		cout << "1. Input Vector\n";
		cout << "2. Show Vector\n";
		cout << "3. Find Min\n";
		cout << "4. Find Max\n";
		cout << "5. Total\n";
		cout << "6. Average\n";
		cout << "7. variance\n";
		cout << "8. Standard Deviation\n";
		cout << "9. Quit\n";
		cout << "----------------\n";
		cin >> choice;
		switch (choice) {
		case '1':
			data = input_vector();
			break;
		case '2':
			show_vector(data);
			break;
		case '3':
			find_min(data);
			break;
		case '4':
			find_max(data);
			break;
		case '5':
			total(data);
			break;
		case '6':
			average(data);
			break;
		case '7':
			variance(data);
			break;
		case '8':
			standard_deviation(data);
			break;
		}
	}
	cout << "see you next time!\n";
}

int main(int argument_count, char ** argument_vector) {
	name_output();
	function();
	return 0;
}
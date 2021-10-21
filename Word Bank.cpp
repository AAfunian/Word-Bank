// Word Bank
// 10.20.2021
// Amir Afunian

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// The nopunc function creates a word bank for a given input file
void nopunc(string& s) {
	vector<string> dictionary;
	for (char& x : s) {
		x = tolower(x);
	}
	// The while loops below are required for exercise 7
	/*
	while (s.find("don't") != string::npos)
		s.replace(s.find("don't"), 5, "do not");
	while (s.find("can't") != string::npos) {
		s.replace(s.find("can't"), 5, "can not");
	}
	*/
	string punc = ".;,?-'()";
	for (char& x : s) {
		for (char i : punc) {
			if (x == i) x = ' ';
		}
	}
	string temp;
	istringstream is{ s };
	while (is >> temp) {
		dictionary.push_back(temp);
		sort(dictionary.begin(), dictionary.end());
	}
	for (int i = 0; i < dictionary.size(); ++i) {
		if (i == 0 || dictionary[i] != dictionary[i - 1]) cout << dictionary[i] << '\n';
	}
}

int main() {
	string fname;
	cout << "Please enter a file name to get its word bank: ";
	cin >> fname;
	ifstream ist{ fname };
	string store;
	string temp;
	while (ist && !ist.eof() && !ist.bad() && !ist.fail()) {
		getline(ist, temp);
		for (char x : temp) {
			store.push_back(x);
		}
	}
	nopunc(store);

	return 0;
}
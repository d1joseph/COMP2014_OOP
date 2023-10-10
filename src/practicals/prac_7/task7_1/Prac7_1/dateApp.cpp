#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

#include "Date.h"

using namespace std;

int main() {
	int day = 0;
	int month = 0;
	int year = 0;
	
	// input date file
	ifstream fin;
	fin.open("date_in.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	//output date file
	ofstream fout;
	fout.open("date_out.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}
	
	string content;
	if (fin.is_open()) {
		while(getline(fin, content)) {
			// Find the positions of '/' characters
			size_t pos1 = content.find('/');
			size_t pos2 = content.find('/', pos1 + 1);

			if (pos1 != string::npos && pos2 != string::npos) {
				// Extract substrings for day, month, and year
				string dayStr = content.substr(0, pos1);
				string monthStr = content.substr(pos1 + 1, pos2 - pos1 - 1);
				string yearStr = content.substr(pos2 + 1);

				// Convert the substrings to integers
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);

				// Check if the conversion was successful
				if (day >= 1 && day <= 31 && month >= 1 && month <= 12) {
					Date d(day, month, year);
					cout << d << endl;
					fout << d << endl;
				} else {
					cout << "Invalid date format: " << content << endl;
				}
			} else {
				cout << "Invalid date format: " << content << endl;
			}
		}
	}

	fin.close();
	fout.close();
	
	return 0;
}

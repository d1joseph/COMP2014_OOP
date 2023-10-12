//addressBookType.h 
 
#ifndef H_addressBookType
#define H_addressBookType
  
#include <string>
#include <fstream>
#include "extPersonType.h"
#include "addressType.h"

using namespace std;

class addressBookType
{
public:
    addressBookType();
    void print() const;
    void loadData();
    void saveData();
private:
    extPersonType list[500];
    int length;
};

void addressBookType::print() const
{
    for (int i = 0; i < length; i++)
        list[i].printInfo();
}

addressBookType::addressBookType()
{
    length = 0;
}

void addressBookType::loadData() {
	ifstream infile;

	char filename[50];

	cout << "Enter file name: ";
	cin >> filename;
	cout << endl;

	infile.open(filename);
	if (!infile) {
		cout << "Input file does not exists. " << "Program terminates!!!"
				<< endl;
		return;
	}

	string first, last;
	int day,month,year;
    string street, city, state, zip, phone, pStatus;

	int i = 0;
	while (infile >> first) {
		infile >> last >> month >> day >> year;
		infile.ignore(100, '\n');
		getline(infile, street);
		infile >> city >> state >> zip >> phone >> pStatus;
		extPersonType temp(first, last, month, day, year, street, city, state, zip,
				phone, pStatus);

	    list[i] = temp;
		i++;
	}
	length = i;

	infile.close();
}

void addressBookType::saveData()
{
	ofstream outFile;
	outFile.open("dataOut.txt");

    string street, city, state, zip, phone, pStatus;

    for (int i = 0; i < length; i++)
    {
    	//Add code here to store all address data in list into the file dataOut.txt
		addressType address = list[i].getAddress();
		address.getDetails(street, city, state, zip);

		outFile << "First Name: " << list[i].getFirstName() << "\n" << "Last Name: " << list[i].getLastName() << "\n";
    	outFile << "Address: " << street << " " << city << " " << state << " " << zip << " " << endl << endl;

    }
    outFile.close();
}

#endif

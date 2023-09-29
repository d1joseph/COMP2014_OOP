#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "student.h"

int main() {
    cout << "Student Registration Program" << endl;
    
    string name;
    int numOfUnits;

    cout << "Enter student name:";
    getline(cin, name);
    cout << "Enter number of units to enrol:";
    cin >> numOfUnits;

    // consume the \n character left in the input buffer from cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Student *s = new Student(name, numOfUnits);
    s->getName();
    s->setUnits();
    s->getUnitList();

    delete s;

    return 0;
}
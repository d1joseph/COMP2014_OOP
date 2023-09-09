#include<iostream>
#include<string>

using namespace std;

#include "student.h"


int main() {
    cout << "Student Registration Program" << endl;
    string name;
    int numOfUnits;

    cout << "Enter student name:";
    cin >> name;
    cout << "Enter number of units to enrol:";
    cin >> numOfUnits;

    cout<<name<<" "<<numOfUnits;
    
    Student *s = new Student(name, numOfUnits);
    // get student name
    s->getName();
    // enrol student units
    s->setUnits();
    // get student enrolled unit list
    s->getUnitList();

    return 0;
}
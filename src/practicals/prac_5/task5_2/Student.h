#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
private:
    string name;
    int numOfUnits;
    string* unitList; 
public:
    Student(string name, int numOfUnits);
    ~Student();
    void getName();
    void getUnitList();
    void setUnits();
    void getUnit(string&);
};

Student::Student(string name, int numOfUnits) {
    unitList = new string[numOfUnits];
}

Student::~Student() {
    delete[] unitList;
}

void Student::getName() {
    cout << name;
}

void Student::getUnitList() {
    for (int unit = 0; unit < numOfUnits; unit++) {
        cout << unitList[unit];
        cout << " ";
    }
}

void Student::setUnits() {
    for (int i = 0; i <= numOfUnits; i++)
    {
        cout << endl
             << "Enter subject for unit "
             << i << endl;
        getUnit(unitList[i-1]);
    }
}

void Student::getUnit(string& unit) {
    cin >> unit;
}

#endif // STUDENT_H_
#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
private:
    string name;
    int numUnits;
    string* unitList; 
public:
    Student(string studentName, int units);
    ~Student();
    void getName();
    void setUnits();
    void getUnitList();
};

Student::Student(string studentName, int units) {
    name = studentName;
    numUnits = units;
    unitList = new string[numUnits];
}

Student::~Student() {
    delete[] unitList;
}

void Student::getName() {
    cout << "student name: " << name << endl;
}

void Student::getUnitList() {
    cout << "student name:" << name << endl;
    cout << "enrolled units:" << endl;

    for (int unit = 0; unit < numUnits; unit++) {
        cout << unit+1 << ". " << unitList[unit] << endl;
    }
    cout << "total units: " << numUnits << endl;
}

void Student::setUnits() {
    delete []unitList;

    string unitName;
    for (int i = 0; i < numUnits; i++) {
        cout << "enter subject " << i + 1 << " name: ";
        cin >> unitName;
        unitList[i] = unitName;
    }
}


#endif // STUDENT_H_
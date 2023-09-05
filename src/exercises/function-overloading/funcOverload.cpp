#include <iostream>

using namespace std;

void DatePrint(int day, int month, int year);
void DatePrint(int day, char Month, int year);
void DatePrint(int month, int day);

int main() {
    DatePrint(30, "Oct", 2021);
    return 0;
}

void DatePrint(int day, int month, int year) {
    cout << "1" << endl;
}

void DatePrint(int day, char month, int year) {
    cout << "2" << endl;
}

void DatePrint(int month, int day) {
    cout << "3" << endl;
}
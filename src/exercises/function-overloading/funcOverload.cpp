#include <iostream>
#include <string>

using namespace std;

void DatePrint(int day, int month, int year);
void DatePrint(int day, string Month, int year);
void DatePrint(int month, int day);

int main() {
    string month = "Oct";
    int monthNum = 10;
    DatePrint(30, month, 2021);
    return 0;
}

void DatePrint(int day, int month, int year) {
    cout << "1" << endl;
}

void DatePrint(int day, string month, int year) {
    cout << "2" << endl;
}

void DatePrint(int month, int day) {
    cout << "3" << endl;
}
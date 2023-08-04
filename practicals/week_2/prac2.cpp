#include <iostream>
#include <string>

using namespace std;

// task 2.1 - overloading example
void testDefaultArg();
void testDefaultArg(int day);
void testDefaultArg(int day, string month);
void testDefaultArg(int day, string month, int year);

void testDefaultArg(int day, string month, int year)
{  
    cout << "Today is " << day << " "
    << month << " " << year << endl;
}

void testDefaultArg(int day)
{
    cout << "Today is " << day << endl;
}

void testDefaultArg(int day, string month)
{
    cout << "Today is " << day << " "
    << month << endl;
}

void testDefaultArg()
{
    cout << "Today is a beautiful day" << endl;
}

// task 2.2 - getQuotientAndRemainder
int getQuotientAndRemainder(int &numerator, int &denominator)
{
    
}
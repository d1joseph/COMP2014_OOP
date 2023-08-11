// practical 2 tasks
// author: Dhiv Joseph
// studentId: 18225899

#include <iostream>
#include <string>

using namespace std;

// task 2.1 declaration - declaring a function to overload
void testDefaultArg();
void testDefaultArg(int day);
void testDefaultArg(int day, string month);
void testDefaultArg(int day, string month, int year);

void testDefaultArg(int day, string month, int year)
// task 2.1 definition - testDefaultArg takes the day, month and year
// as overloaded input parameters and outputs a string with
// based on the given parameters.
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

void getQuotientAndRemainder(int& numerator, int& denominator)
// task 2.2 - getQuotientAndRemainder takes a numerator and denominator
// as input parameters by reference, and outputs their quotient and remainder.
{
    int quotient = numerator / denominator;
    int remainder = numerator % denominator;

    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
}

void sort(int& a, int& b, int& c)
// task 2.3 - sort takes three integer values by reference as input
// parameters, by reference and sorts the values of a, b and c in ascending order
{
    int tmp;

    if (a > c) {
        tmp = a;
        a = c;
        c = tmp;
    }

    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    if (b > c) {
        tmp = c;
        c = b;
        b = tmp;
    }

    cout << a << " " << b << " "<< c << endl;
}

int calculateTotalCost(int olLength, int uwLength, int olCPM, int uwCPM)
// task 2.4 - calculateTotalCost is a helper function
// to calculatePowerlineLength, which returns the totalCost of
// calculated from the given parameters.
{
    int totalCost = olCPM * olLength + uwCPM * uwLength;
    return totalCost;
}

void calculatePowerlineLength()
// task 2.4 - calculatePowerlineLength outputs the most economical length
// of powerlines to run underwater (uw) and/or overland (ol), as well as the total cost (c).
{   
    int width, distance, totalDistance; // width of river and distance of factory downstream
    int uwCPM, olCPM, totalCost; // underwater and overland cost per meter, and total cost
    int uwLength, olLength; // most economical length of powerline underwater and overland

    // input non-negative width of the river
    do {
        cout << "enter the width of the river (meters): " << endl;
        cin >> width;
    } while (width < 0);

    // input non-negative distance of the factory downstream across the river
    do {
        cout << "enter the distance of the factory downstream (meters): " << endl;
        cin >> distance;
    } while (distance < 0);

    // input non-negative unit cost of laying the powerline underwater
    do {
        cout << "enter the unit cost of powerline underwater ($ cost per meter): " << endl;
        cin >> uwCPM;
    } while (uwCPM < 0);

    // input non-negative unit cost of laying the powerline overland, l
    do {
        cout << "enter the unit cost of powerline overland ($ per meter): " << endl;
        cin >> olCPM;
    } while (olCPM < 0);

    totalDistance = width + distance;

    olLength = totalDistance;
    uwLength = totalDistance;

    int totalOverlandCost = calculateTotalCost(olLength, 0, olCPM, uwCPM);
    int totalUnderwaterCost = calculateTotalCost(0, uwLength, olCPM, uwCPM);

    if (totalOverlandCost <= totalUnderwaterCost) {
        olLength = totalDistance;
        uwLength = 0;
    } else {
        olLength = 0;
        uwLength = totalDistance;
    }

    cout << "optimal lengths" << endl;
    cout << "overland: " << olLength << " meters" << endl;
    cout << "underwater: " << uwLength << " meters" << endl;

    int optimalCost = calculateTotalCost(olLength, uwLength, olCPM, uwCPM);
    cout << "optimal total cost: $" << optimalCost << endl;
}

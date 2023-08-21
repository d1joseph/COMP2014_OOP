// practical 2 tasks
// author: Dhiv Joseph
// studentId: 18225899

#include <iostream>
#include <string>
#include <cmath>

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

void getQuotientAndRemainder(int& numerator, int& denominator, int& quotient, int& remainder)
// task 2.2 - getQuotientAndRemainder takes a numerator, denominator, quotient and remainder
// as input parameters by reference, and outputs the quotient and remainder.
{
    quotient = numerator / denominator;
    remainder = numerator % denominator;

    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
}

void swap(int& a, int& b)
// task 2.3 - swap is a helper function that swaps the values of input
// parameters a and b by reference.
{
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
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

double calculateCost(int &underwaterDist, int &overlandDist, int &underwaterCost, int &overlandCost)
// task 2.4 - calculateCost is a helper function to calculate the total cost for the project described
// in task 2.4 ...
{
    int totalCost = underwaterDist * underwaterCost + overlandDist * overlandCost;
    return totalCost;
}

void calculateOptimalLength(int &riverWidth, int &factoryDistance, int &underwaterCost, int &overlandCost)
// task 2.4 - calculateOptimalLength calculates and outputs the optimal length
// using the width, distance, costX and costY parameters ...
{   
    int minCost = INT_MAX;
    int runningCalc;
    int overlandDist, minOverlandDist;
    int underwaterDist, minUnderwaterDist;

    // loop through x to find minCost
    for (int x = 0; x < factoryDistance; x++) {
        overlandDist = x;
        runningCalc = factoryDistance - x;
        underwaterDist = sqrt((riverWidth * riverWidth) + (runningCalc * runningCalc));
        
        int cost = calculateCost(underwaterDist, overlandDist, underwaterCost, overlandCost);

        if (minCost > cost) {
            minCost = cost;
            minUnderwaterDist = underwaterDist;
            minOverlandDist = overlandDist;
        }

    }

    cout << "optimum length underwater: " << minUnderwaterDist << "m" << endl;
    cout << "optimum length overland: " << minOverlandDist << "m" << endl;
    cout << "projected cost: $" << minCost << endl;
}

int main()
{   
    int w, d; // riverwidth and factory distance downstream
    int costY, costX; // costY is underwater, costX is overland per meter

    cout << "enter river width (meters): " << endl;
    cin >> w;
    cout << "enter factory distance downstream (meters): " << endl;
    cin >> d;
    cout << "enter underwater cost per meter ($): " << endl;
    cin >> costY;
    cout << "enter overland cost per meter ($): " << endl;
    cin >> costX;

    int maxProjectedCost = calculateCost(w, d, costY, costX);
    cout << "projected max cost: $" << maxProjectedCost << endl;
    
    calculateOptimalLength(w, d, costY, costX);

    return 0;
}

// practical 1 tasks
// author: Dhiv Joseph
// studentId: 18225899

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "prac1.h"

using namespace std;

void weather()
// Task 1.2 - A simple weather function that takes the month and day as integers
// as user input and returns a random weather status.
{
    int month, day;
    
    cout << "Welcome to your friendly weather program.\n"
    << "Enter today's date as two integers for the month and the day:\n";
    
    cin >> month;
    cin >> day; 
    
    srand(month * day);
    int prediction;
    char ans;
    
    cout << "Weather for today:\n";
    
    do {
        prediction = rand() % 3;
    
        switch (prediction) {
        case 0:
            cout << "The day will be sunny!!\n";
            break;
        case 1:
            cout << "The day will be cloudy.\n";
            break;
        case 2:
            cout << "The day will be stormy!.\n";
            break;
        default:
            cout << "Weather program is not functioning properly.\n";
        }
    
        cout << "Want the weather for the next day?(y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');
    
    cout << "That's it from your 24 hour weather program.\n";
}

double setDailySales()
// Task 1.3 - Returns the dollar value of daily sales from dailySalesInput
// parameter input by the user.
{
    double dailySales;

    cout << "Enter daily sales (e.g 1516.99)" << endl;
    cin >> dailySales;

    return dailySales;
}

double calculateCommission(double dailySales)
// Task 1.3 - Calculates and returns the commission from the dailySales
// parameter. Commission is calculated as a % of dailySales based on
// a range.
{   
    double commission = 0.0; // default commission

    // handle negative values
    if (dailySales < 0.0) {
        cout << "dailySales must be greater than 0" << endl;
        return commission;
    }

    // determine the commission %
    // $0-$999: 3%
    if (dailySales >= 0.0 && dailySales <= 999.0) {
        commission = 3.0 / 100.0;
    // $1000-$2999: 3.5%
    } else if (dailySales >= 1000.0 && dailySales <= 2999.0) {
        commission = 3.5 / 100.0; // 3.5%
    // $3000+: 4.5%
    } else if (dailySales >= 3000.0) {
        commission = 4.5 / 100.0; // 4.5%
    }

    cout << "eligible commision rate: " << (commission * 100) << "%" << endl;

    double calculatedComms = dailySales * commission;

    return round(calculatedComms * 100.0) / 100.0; // round results to 2 decimal places
}

void printMultiplicationTable()
// Task 1.4 - Prints the multiplication tables for numbers 1 to 10.
{
    for (int i = 1; i <= 10; i++) {
        // cout << "multiplying: " << i << endl;
        for (int j = 1; j <= 10; j++) {
            cout << i << " x " << j << " = " << (i * j) << "\t"; 
        }
        cout<<endl;
    }
}


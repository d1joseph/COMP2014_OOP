/**
* About: implements Task3_1.cpp in OOP
* Author: 18225899
* Date: 22 August 2023
**/

#include <iostream>
#include "Task4_2.h"

using namespace std;

int main( )
{
    int size;
    cout << "enter desired size of array:" << endl;
    cin >> size;
    OneDArray arr(size);
    arr.fillArray();
    
    int target;
    cout << "enter a number to search:" << endl;
    cin >> target;
    arr.search(target);

    arr.printArray();
    
    return 0;
}

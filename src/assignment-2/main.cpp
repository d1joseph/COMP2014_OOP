/*
Student: Dhivyan Joseph
StudentID: 18225899
About: COMP2014 OOP Assignment 2 - EV charging schedule system
Compiler: g++.exe (Rev7, Built by MSYS2 project) 13.1.0

I hold a copy of this assignment that I can produce if the original is lost or damaged.
I hereby certify that no part of this assignment has been copied from any other student’s work or
from any other source except where due acknowledgement is made in the assignment. No part
of this assignment has been written/produced for me by another person except where such
collaboration has been authorised by the subject lecturer concerned.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

#include "Constant.h"
#include "ChargingAllocation.h"
#include "DemandGenerator.h"
#include "Vehicle.h"
#include "ChargingStation.h"
#include "lib/Utilities.cpp"

using namespace std;

int main() {
    srand(time(0));
    cout << "### EV Charging Scheduler v0 ###" << endl << endl;
    
    int testId = 0;
    string testCity = NAME_MAP[testId];
    int testDistance = DISTANCE_MAP[testId];
    int testNumOfChargers = CHARGERS_MAP[testId];
    
    ChargingStation *s = new ChargingStation(
        testId,
        testCity,
        testDistance,
        testNumOfChargers
    );

    delete s;
    
    Vehicle *v = new Vehicle();
    v->getAllAttributes();
    v->getFarthestCityInRange();
    
    delete v;
}
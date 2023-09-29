// Student: Dhivyan Joseph
// StudentID: 18225899
// About: COMP2014 OOP Assignment 2 - EV charging schedule system

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Constant.h"
#include "ChargingAllocation.h"
#include "DemandGenerator.h"
#include "Vehicle.h"
#include "ChargingStation.h"
#include "Route.h"
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
// Student: Dhivyan Joseph
// StudentID: 18225899
// About: COMP2014 OOP Assignment 2 - EV charging schedule system

#include <iostream>
#include <string>
#include <vector>
#include "Constant.h"
#include "ChargingAllocation.h"
#include "DemandGenerator.h"
#include "Vehicle.h"
#include "ChargingStation.h"

using namespace std;

int main() {
    cout << "### EV Charging Scheduler v0 ###" << endl;
    
    int testId = 0;
    string testCity = NAME_MAP[0];
    int testDistance = DISTANCE_MAP[0];
    int testNumOfChargers = CHARGERS_MAP[0];

    ChargingStation *s = new ChargingStation(
        testId,
        testCity,
        testDistance,
        testNumOfChargers
    );
    s->distanceToSydney(2);
    s->getAllAttributes();

    // Vehicle *v = new Vehicle();
    // v->getAllAttributes();
}
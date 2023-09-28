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
    
    string city = NAME_MAP[0];
    
    ChargingStation *s = new ChargingStation(1, city, 802, 10);
    int o = s->distanceToSydney(0);
    cout << "value: " << o << endl;

    Vehicle *v = new Vehicle();
    v->getAllAttributes();
}
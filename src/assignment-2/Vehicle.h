#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "lib/Utilities.h"

class Vehicle {
private:
    int vehicleId;
    int currentCityId;
    int destinationId;
    int capacityRange;
    int remainingRange;
    bool isCharging;
    bool fullCharge;
public:
    Vehicle();
    Vehicle(int& id, int& cId, int& dId, int& capacity, int& remaining);
    ~Vehicle();
    void getVehicleInformation() const; // print out all attributes
    int getFarthestCityInRange() const; // calculate the farthest city in remainingRange
    bool setAttributes(const string&);
};

Vehicle::Vehicle() {
    vehicleId = 0;
    currentCityId = 0;
    destinationId = 0;
    capacityRange = MAX_CAPACITY;
    remainingRange = 0;
}

Vehicle::Vehicle(int& id, int& cId, int& dId, int& capacity, int& remaining):
vehicleId(id),
currentCityId(cId),
destinationId(dId),
capacityRange(capacity),
remainingRange(remaining)
{
    fullCharge = true;
}

Vehicle::~Vehicle() {
    
}

void Vehicle::getVehicleInformation() const {
    cout << setw(5) << vehicleId << setw(20) << NAME_MAP[currentCityId] << setw(20)
    <<  NAME_MAP[destinationId] << setw(20) << capacityRange << setw(20) << remainingRange << endl;
}

// return the cityId of the farthest city in range given
// it's current battery %. If battery is full, return cityId
// of next charging station.

int Vehicle::getFarthestCityInRange() const {
    // if battery full return next charging station from currentCity
    if (fullCharge) {
        cout << "next charging station: " << NAME_MAP[currentCityId + 1] << endl;
        return currentCityId  + 1;
    }

    // calculate farthest city given remainingRange
    int farthestCityId = currentCityId;

    return 0;
}

bool Vehicle::setAttributes(const string& line) {
    string lineWithoutBrackets = line.substr(1, line.length() - 2);
    stringstream ss(lineWithoutBrackets);

    char discard;
    if (
        ss >>
        vehicleId >> 
        discard >>
        destinationId >> 
        discard >>
        capacityRange >> 
        discard >>
        remainingRange
    ) {return true;}

    return false; // parsing failed
}

#endif // VEHICLE_H_

#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
private:
    int vehicleId; // can be any integer
    int currentCityId; // initialised with 0 for Sydney
    int destinationId; // any city other than Sydney
    int capacityRange; // in kilometers
    int remainingRange; // in kilometers
public:
    Vehicle();
    ~Vehicle();
    void getAllAttributes();
};

Vehicle::Vehicle() {
    vehicleId = 0;
    currentCityId = 0;
    destinationId = 0;
    capacityRange = 1000;
    remainingRange = 1000;
}

Vehicle::~Vehicle() {
    
}

void Vehicle::getAllAttributes() {
    cout << "vehicleId: " << vehicleId << endl;
    cout << "currentCityId: " << currentCityId << endl;
    cout << "destinationId: " << destinationId << endl;
    cout << "capacityRange: " << capacityRange << endl;
    cout << "remainingRange: " << remainingRange << endl;
}

#endif // VEHICLE_H_

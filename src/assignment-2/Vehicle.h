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
    void getAllAttributes(); // print out all attributes
    int getFarthestCityInRange(); // calculate the farthest city in remainingRange
};

Vehicle::Vehicle() {
    vehicleId = 0; // generate a uid
    currentCityId = 0; // need to keep track of this at runtime
    destinationId = 0; // does not change once set
    capacityRange = 1000; // change to randomised value on init
    remainingRange = 1000; // change to randomised value on init
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

// return the cityId of the farthest city in range given
// it's current battery %. If battery is full, return cityId
// of next charging station.

// by default, it should return "Campbelltown" cityId
int Vehicle::getFarthestCityInRange() {
    // if battery full, if so, return next charging station
    if (capacityRange == 1000) {
        cout << "next charging station: " << NAME_MAP[currentCityId + 1] << endl;
        return currentCityId + 1;
    }
    return 0;
}

#endif // VEHICLE_H_

#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
private:
    int vehicleId;
    int currentCityId;
    int destinationId;
    int capacityRange;
    int remainingRange;
public:
    Vehicle();
    Vehicle(int& id, int& cId, int& dId, int& capacity, int& remaining);
    ~Vehicle();
    void getVehicleInformation() const;
    int getVehicleId() const;
    int getCurrentCityId() const;
    int getDestinationId() const;
    int getRemainingRange() const;
    int getFarthestCityInRange() const;
    bool setAttributes(const string&);
    void setCurrentCityId(int&);
    void setRemainingRange();
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
remainingRange(remaining){}

Vehicle::~Vehicle() {
    
}

void Vehicle::getVehicleInformation() const {
    cout << setw(5) << vehicleId << setw(20) << NAME_MAP[currentCityId] << setw(20)
    <<  NAME_MAP[destinationId] << setw(20) << capacityRange << setw(20) << remainingRange << endl;
}

int Vehicle::getVehicleId() const {
    return vehicleId;
}

int Vehicle::getCurrentCityId() const {
    return currentCityId;
}

int Vehicle::getDestinationId() const {
    return destinationId;
}

int Vehicle::getRemainingRange() const {
    return remainingRange;
}

int Vehicle::getFarthestCityInRange() const {
    int totalDistance = 0;
    int farthestCityId = currentCityId;

    // Iterate through the distance map to find the farthest city within the remaining range
    for (int cityId = currentCityId + 1; cityId < NUM_CITIES; cityId++) {
        totalDistance += DISTANCE_MAP[cityId - 1];

        // Check if the total distance exceeds the remaining range
        if (totalDistance > remainingRange) {
            break; // The farthest city is within the remaining range
        }

        farthestCityId = cityId;
    }

    return farthestCityId;
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

    return false;
}

void Vehicle::setCurrentCityId(int& cityId) {
    currentCityId = cityId;
}

void Vehicle::setRemainingRange() {
    
}

#endif // VEHICLE_H_

#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
private:
    int vehicleId;
    int currentCityId;
    int destinationId;
    int capacityRange;
    int remainingRange;
    int farthestCityId;
    int nextFarthestCityId;
public:
    Vehicle();
    Vehicle(int& id, int& cId, int& dId, int& capacity, int& remaining);
    ~Vehicle();
    void getVehicleInformation() const;
    int getVehicleId() const;
    int getCurrentCityId() const;
    int getDestinationId() const;
    int getCapacityRange() const;
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
    int farthestCityId = 0;
    int nextFarthestCityId = 0;
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

int Vehicle::getCapacityRange() const {
    return capacityRange;
}

int Vehicle::getRemainingRange() const {
    return remainingRange;
}

int Vehicle::getFarthestCityInRange() const {
    int totalDistance = 0;
    int farthestCityId = currentCityId;

    for (int cityId = currentCityId + 1; cityId < NUM_CITIES; cityId++) {
        totalDistance += DISTANCE_MAP[cityId - 1];

        if (totalDistance > remainingRange) {
            break;
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

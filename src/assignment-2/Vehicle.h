#ifndef VEHICLE_H_
#define VEHICLE_H_

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
    void getVehicleInformation() const;
    int getFarthestCityInRange() const;
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

int Vehicle::getFarthestCityInRange() const {
    if (fullCharge) {
        cout << "next charging station: " << NAME_MAP[currentCityId + 1] << endl;
        return currentCityId  + 1;
    }

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

    return false;
}

#endif // VEHICLE_H_

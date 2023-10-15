#ifndef CHARGINGSTATION_H_
#define CHARGINGSTATION_H_

class ChargingStation {
private:
    int cityId;
    string cityName;
    int distanceToLastCity;
    int numberOfChargers;
public:
    ChargingStation(
        int cityId,
        string cityName,
        int distanceToLastCity,
        int numberOfChargers
    );
    ~ChargingStation();
    // getAllAttributes
    void getStationInformation() const;
    static int distanceToSydney(int cityId);
};

ChargingStation::ChargingStation(
    int id,
    string name,
    int distance,
    int numChargers
) {
    cityId = id;
    cityName = name;
    distanceToLastCity = distance;
    numberOfChargers = numChargers;
}

ChargingStation::~ChargingStation() {

}

void ChargingStation::getStationInformation() const {
    cout << setw(5) << cityId << setw(20) << cityName << setw(20)
    <<  distanceToSydney(cityId) << setw(20) << numberOfChargers << endl;
}

int ChargingStation::distanceToSydney(int cityId) {
    if (cityId < 0 | cityId > NUM_CITIES) {
        cout << "error: invalid cityId" << endl;
        return -1;
    } else if (cityId == 0) {
        return 0; // already at sydney
    }

    int distance = 0;
    for (int index = cityId; index >= 0; index--) {
        distance += DISTANCE_MAP[index];
    }
    
    return distance;
}

#endif // CHARGINGSTATION_H_

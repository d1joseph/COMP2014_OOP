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
    void getAllAttributes() const;
    int distanceToSydney(int cityId);
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

void ChargingStation::getAllAttributes() const {
    cout << "cityId: " << cityId << endl;
    cout << "cityName: "<< cityName << endl;
    cout << "distanceTolastCity: " << distanceToLastCity << endl;
    cout << "numberOfChargers: " << numberOfChargers << endl;
}

int ChargingStation::distanceToSydney(int cityId) {
    int distance = 0;
    
    if (cityId < 0 | cityId > NUM_CITIES) {
        cout << "error: invalid cityId" << endl;
        return -1;
    } else if (cityId == 0) {
        return 0;
    }

    for (int index = cityId; index >= 0; index--) {
        distance += DISTANCE_MAP[index];
    }
    
    return distance;
}

#endif // CHARGINGSTATION_H_

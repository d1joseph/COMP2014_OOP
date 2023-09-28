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
    void getAllAttributes();
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

void ChargingStation::getAllAttributes() {
    cout << "cityId: " << cityId << endl;
    cout << "cityName: "<< cityName << endl;
    cout << "distanceTolastCity: " << distanceToLastCity << endl;
    cout << "numberOfChargers: " << numberOfChargers << endl;
}

int ChargingStation::distanceToSydney(int cityId) {
    if (cityId == 0) {
        return 0;
    }

    // calculate the distance from Sydney to cityId
    int len = NAME_MAP_LENGTH;
    return len;
}

#endif // CHARGINGSTATION_H_

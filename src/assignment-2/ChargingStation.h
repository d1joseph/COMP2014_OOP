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

#endif // CHARGINGSTATION_H_

#ifndef EVCHARGING_H_
#define EVCHARGING_H_

class EVCharging {
private:
    // ChargingStation
    <ChargingStation> chargingStations;
    // vector of EVs
    <Vehicle> vehicles;
    DemandGenerator demands;
public:
    // start
    EVCharging();
    ~EVCharging();
};

EVCharging::EVCharging() {
    for (int s = 0; s < NUM_CITIES; s++) {
        ChargingStation chargingStation(i, NAME_MAP[i], DISTANCE_MAP[i], CHARGERS_MAP[i]);
        chargingStations.push_back(chargingStation);
    }
}

EVCharging::~EVCharging() {
    cout << "shutting down EVS." << endl;
}

#endif // EVCHARGING_H_
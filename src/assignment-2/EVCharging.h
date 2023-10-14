#ifndef EVCHARGING_H_
#define EVCHARGING_H_

class EVCharging {
private:
    vector<ChargingStation> chargingStations;
public:
    EVCharging();
    ~EVCharging();
    void getChargingStations() const;
    void load() const;
    void getDemand() const;
    void run() const;
};

EVCharging::EVCharging() {
    // init charging stations
    for (int s = 0; s < NUM_CITIES; s++) {
        ChargingStation chargingStation(s, NAME_MAP[s], DISTANCE_MAP[s], CHARGERS_MAP[s]);
        chargingStations.push_back(chargingStation);
    }

    // generate demand
}

EVCharging::~EVCharging() {}

void EVCharging::getChargingStations() const {
    cout << "Charging Station information:" << endl;
    
    // column headers
    cout << setw(5) << "Location Id" << setw(20) << "Location Name" << setw(20)
    <<  "Distance To Sydney" << setw(20) << "no of Chargers" << endl;

    for (int stationId = 0; stationId < NUM_CITIES; stationId++) {
        chargingStations[stationId].getStationInformation();
    }
}

void EVCharging::load() const {}

void EVCharging::getDemand() const {}

void EVCharging::run() const {
    // populate vehicles with demand data
    // output demand of each vehicle
    // output information for each charging station
    getChargingStations();
    // allocate vehicles to charging stations
    // output information about allocation with average wait times
    // improve allocation
    // output information about allocation with average wait times
}

#endif // EVCHARGING_H_
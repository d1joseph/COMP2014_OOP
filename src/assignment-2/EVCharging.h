#ifndef EVCHARGING_H_
#define EVCHARGING_H_

#include "Vehicle.h"

class EVCharging {
private:
    vector<ChargingStation> chargingStations;
    vector<Vehicle> vehicles;
public:
    EVCharging();
    ~EVCharging();
    void getChargingStations() const;
    void load(fstream& demandFile, string& fileName) const;
    void getVehicles() const;
    void run() const;
};

EVCharging::EVCharging() {
    // init charging stations
    for (int s = 0; s < NUM_CITIES; s++) {
        ChargingStation chargingStation(s, NAME_MAP[s], DISTANCE_MAP[s], CHARGERS_MAP[s]);
        chargingStations.push_back(chargingStation);
    }

    for (int v = 0; v < MAX_DEMANDS; v++) {
        int id = MAX_DEMANDS + v;
        int currentCity = 0;
        int destinationId = 11;
        int capacityRange = MAX_CAPACITY;
        int remainingRange = GenerateRemainingRange();

        Vehicle testVehicle(id, currentCity, destinationId, capacityRange, remainingRange);
        vehicles.push_back(testVehicle);
    }
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

void EVCharging::load(fstream& demandFile, string& fileName) const {
    cout << "reading file: " << fileName << endl << endl;
    // load the demand data into each vehicle object
    // add each vehicle to the vehicles vector
    // generate demand
}

void EVCharging::getVehicles() const {
    cout << "Vehicle information:" << endl;

    cout << setw(5) << "vehicleId" << setw(20) << "Origin" << setw(20)
    <<  "Destination" << setw(20) << "Capacity Range" << setw(20) << "Remaining Range" << endl;

    for (int vehicleId = 0; vehicleId < MAX_DEMANDS; vehicleId++) {
        vehicles[vehicleId].getVehicleInformation();
    }

    cout << endl;
}

void EVCharging::run() const {
    // output demand information of each vehicle
    string fileName = "ChargingDemands.txt";
    fstream demandFile(fileName);
    load(demandFile, fileName);

    getVehicles();
    
    // output information for each charging station
    getChargingStations();
    // allocate vehicles to charging stations
    // output information about allocation with average wait times
    // improve allocation
    // output information about allocation with average wait times
}

#endif // EVCHARGING_H_
#ifndef EVCHARGING_H_
#define EVCHARGING_H_

class EVCharging {
private:
    vector<ChargingStation> chargingStations;
    vector<Vehicle> vehicles;
    ChargingAllocation chargingAllocator;
public:
    EVCharging();
    ~EVCharging();
    void getChargingStations() const;
    void getVehicles() const;
    int run();
};

EVCharging::EVCharging(): chargingAllocator(&vehicles) {
    // init charging stations
    for (int s = 0; s < NUM_CITIES; s++) {
        ChargingStation chargingStation(s, NAME_MAP[s], DISTANCE_MAP[s], CHARGERS_MAP[s]);
        chargingStations.push_back(chargingStation);
    }
}

EVCharging::~EVCharging() {cout << "Exiting." << endl;}

void EVCharging::getChargingStations() const {
    cout << "Charging Station information:" << endl;
    
    // column headers
    cout << setw(5) << "Location Id" << setw(20) << "Location Name" << setw(20)
    <<  "Distance To Sydney" << setw(20) << "no of Chargers" << endl;

    for (int stationId = 0; stationId < NUM_CITIES; stationId++) {
        chargingStations[stationId].getStationInformation();
    }
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

int EVCharging::run() {

    while (true) {
        string fileName = "ChargingDemands.txt";
        fstream demandFile(fileName);
        DemandGenerator demand;
        demand.Generate(fileName);
    
        chargingAllocator.load(demandFile, fileName);
        getVehicles();
        getChargingStations();
        chargingAllocator.getAllocationInfo();
        chargingAllocator.getQueueLengthAndTime();
    
        cout << "Press ENTER to exit "; // <-- add animated blinking dots `...` here
        if (getchar() != EOF) {
            break; // Exit the loop when any key is pressed
        }

        return 0;
    }

    return -1;
}

#endif // EVCHARGING_H_
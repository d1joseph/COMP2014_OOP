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
    void load(fstream& demandFile, const string& fileName);
    void getVehicles() const;
    void run();
};

EVCharging::EVCharging(): chargingAllocator(&vehicles) {
    // init charging stations
    for (int s = 0; s < NUM_CITIES; s++) {
        ChargingStation chargingStation(s, NAME_MAP[s], DISTANCE_MAP[s], CHARGERS_MAP[s]);
        chargingStations.push_back(chargingStation);
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

void EVCharging::load(fstream& demandFile, const string& fileName) {
    cout << "reading file: " << fileName << endl << endl;
    
    if (!demandFile.is_open()) {
        cerr << "error: could not open '" << fileName << "'" << endl;
        return;
    }

    string line;
    while(getline(demandFile, line)) {
        Vehicle vehicle;
        if (vehicle.setAttributes(line)) {
            vehicles.push_back(vehicle);
        } else {
            cerr << "error: unable to parse data from line: " << line << endl;
        }
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

void EVCharging::run() {
    string fileName = "ChargingDemands.txt";
    fstream demandFile(fileName);
    
    if (!filesystem::exists(fileName)) {
        DemandGenerator demand;
        demand.Generate(fileName);
    }

    load(demandFile, fileName);

    getVehicles();
    
    getChargingStations();

    // allocate vehicles to charging stations
    // output information about allocation with average wait times
    cout << "Vehicle information using chargingAllocator:" << endl;
    for (const Vehicle& vehicle : vehicles) {
        chargingAllocator.displayVehicleInfo(vehicle);
    }

    // improve allocation
    // output information about allocation with average wait times
}

#endif // EVCHARGING_H_
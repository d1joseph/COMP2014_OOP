#ifndef CHARGINGALLOCATION_H_
#define CHARGINGALLOCATION_H_

class ChargingAllocation {
private:
    vector<Vehicle>* vehicles;
public:
    ChargingAllocation(vector<Vehicle>* vehicles): vehicles(vehicles) {}
    ~ChargingAllocation() {}
    void displayVehicleInfo(const Vehicle& vehicle) const;
    void load(fstream& demandFile, const string& fileName);
};

void ChargingAllocation::displayVehicleInfo(const Vehicle& vehicle) const {
    vehicle.getVehicleInformation();
}

void ChargingAllocation::load(std::fstream& demandFile, const std::string& fileName) {
    cout << "reading file: " << fileName << endl << endl;

    if (!demandFile.is_open()) {
        cerr << "error: could not open '" << fileName << "'" << endl;
        return;
    }

    std::string line;
    while (getline(demandFile, line)) {
        Vehicle vehicle;
        if (vehicle.setAttributes(line)) {
            vehicles->push_back(vehicle);
        } else {
            cerr << "error: unable to parse data from line: " << line << endl;
        }
    }
}

#endif // CHARGINGALLOCATION_H_

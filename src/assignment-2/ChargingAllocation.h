#ifndef CHARGINGALLOCATION_H_
#define CHARGINGALLOCATION_H_

class ChargingAllocation {
private:
    vector<Vehicle>* vehicles;
public:
    ChargingAllocation(vector<Vehicle>* vehicles): vehicles(vehicles) {}
    ~ChargingAllocation() {}
    void displayVehicleInfo(const Vehicle& vehicle) const;
    void getAllocationInfo();
    void getQueueLengthAndTime();
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

void ChargingAllocation::getAllocationInfo() {
    cout << "Initial charging allocation:" << endl;
    cout << setw(20) << "Vehicle Id" << setw(20) << "Destination" << setw(20) << "Capacity Range"
    << setw(20) << "Remaining Range" << setw(20) << "First Recharge" << setw(20) << "Second Recharge" << endl ;
    
    for (auto& vehicle : *vehicles) {
        // Calculate the farthest city the vehicle can reach within remainRange
        int firstCityId = vehicle.getFarthestCityInRange();

        // Display the result
        cout << setw(20) << vehicle.getVehicleId() << setw(20) << NAME_MAP[vehicle.getDestinationId()] << setw(20) 
        << vehicle.getCapacityRange() << setw(20) << vehicle.getRemainingRange() << setw(20) << NAME_MAP[firstCityId]
        << setw(20) << "----"<<  endl;
    }
}

void ChargingAllocation::getQueueLengthAndTime(){
    cout << setw(5) << "Location Id" << setw(20) << "Location Name" << setw(20) 
    << "no of Chargers" << setw(20) << "Queue Length" << setw(20) << "Waiting hours" <<endl;

    const int maxCities = 12;  // Maximum number of cities, adjust as needed
    int queueLengths[maxCities] = {0};  // Initialize queue lengths to 0

    for (const auto& vehicle : *vehicles) {
        // Increment the queue length for the destination city of each vehicle
        queueLengths[vehicle.getFarthestCityInRange()]++;
    }

    // Display the queue lengths for each city

    for (int i = 1; i < maxCities; ++i)
    {
         // Calculate average waiting time
        double averageWaitingTime[maxCities] = {0};
        averageWaitingTime[i] = 0.5 * (double(queueLengths[i]) / double(CHARGERS_MAP[i]));


        cout << setw(5) << i << setw(20) << NAME_MAP[i] << setw(20) << CHARGERS_MAP[i] << setw(20) 
        << queueLengths[i] << setw(20) << averageWaitingTime[i] << endl;
    }
}

#endif // CHARGINGALLOCATION_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Vehicle.h"
#include "../../../assignment-2/Constant.h"

using namespace std;

// parses demand data into a Vehicle object, and returns the object
Vehicle ParseDataIntoVehicle(const string& line) {
    string lineWithoutBrackets = line.substr(1, line.length() - 2);
    stringstream ss(lineWithoutBrackets);
    Vehicle vehicle;

    char discard;
    ss >>
    vehicle.VehicleId >> 
    discard >>
    vehicle.DestinationId >> 
    discard >>
    vehicle.CapacityRange >> 
    discard >>
    vehicle.RemainingRange;
    
    return vehicle;
}

// print out all vehicles in the vector and total count stored
static void getAllVehicles(vector<Vehicle>& vehicles) {
    int listLength = vehicles.size();
    for (int vehicle = 0; vehicle < listLength; vehicle++) {
        cout << "vehicleId: " << vehicles[vehicle].VehicleId << endl;
        cout << "currentCityId: " << vehicles[vehicle].CurrentCityId << endl;
        cout << "destinationId: " << vehicles[vehicle].DestinationId << endl;
        cout << "capacityRange: " << vehicles[vehicle].CapacityRange << endl;
        cout << "remainingRange: " << vehicles[vehicle].RemainingRange << endl << endl;
    }
    
    cout << "total vehicles: " << listLength << endl;
}

static int calculateDistance(const int DISTANCE_MAP[], int& currentCityId, int& destinationCityId) {
    if (currentCityId < 0 || destinationCityId >= NUM_CITIES || currentCityId > destinationCityId) {
        return 0;
    }

    int distanceToDestination;
    for (int index = currentCityId; index <= destinationCityId; index++) {
        distanceToDestination += DISTANCE_MAP[index];
    }

    return distanceToDestination;
}

static void deleteVehicle(vector<Vehicle>& vehicles) {
    for (auto it = vehicles.begin(); it != vehicles.end();) {
        int distanceToDestination = calculateDistance(DISTANCE_MAP, it->CurrentCityId, it->DestinationId);
        
        if (it->RemainingRange >= distanceToDestination) {
            it = vehicles.erase(it); // Remove the vehicle from the vector
        } else {
            ++it;
        }
    }
}

int main() {
    vector<Vehicle> vehicles;
    
	ifstream fin;
	fin.open("ChargingDemandsSample.txt");
	if (fin.fail()) {
		cout << "ChargingDemandsSample.txt file opening failed.\n";
		exit(1);
	}
	
	if (fin.is_open()) {
	    string line;
		while(getline(fin, line)) {
            vehicles.push_back(ParseDataIntoVehicle(line));
		}
	}
    fin.close();

    int sizeBefore = vehicles.size();

    deleteVehicle(vehicles);

    int sizeAfter = vehicles.size();

    getAllVehicles(vehicles);
    cout << "size before operation: " << sizeBefore << endl;
    cout << "size after operation: " << sizeAfter << endl;
	
	return 0;
}
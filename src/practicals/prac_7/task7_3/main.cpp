#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Vehicle.h"

using namespace std;

// parses demand data into a Vehicle object, and returns the object
Vehicle ParseDataIntoVehicle(const string& line) {
    string lineWithoutBrackets = line.substr(1, line.length() - 2);
    stringstream ss(lineWithoutBrackets);
    Vehicle vehicle;

    char discard;
    if (
        ss >>
        vehicle.VehicleId >> 
        discard >>
        vehicle.DestinationId >> 
        discard >>
        vehicle.CapacityRange >> 
        discard >>
        vehicle.RemainingRange
    ) {
        return vehicle;
    }
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
    
    cout << "total vehicles: " << listLength;
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

    getAllVehicles(vehicles);
	
	return 0;
}
/* Author: Dhivyan Joseph
   StudentId: 18225899
   Description: A program to generate demand inputs in the format
   [vehicleId, destinationId, capacityRange, remainRange]
   and saved to a text file at a specified location.

   This class is a prototype for the DemandGenerator in assignment 2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "../../../assignment-2/Constant.h"

using namespace std;

struct DemandRequest {
    int VehicleId;
    int DestinationId;
    int CapacityRange;
    int RemainingRange;
};

class DemandGenerator {
private:
    static const int defaultLimit = 100;
    int generationLimit;
    string outputSavePath; // where to save the output file
    ofstream fileOut; // init an fstream object to write the output file

    // generates a random int in a given range
    int getRandomInt(int min, int max) {
        random_device rd;
        mt19937 generator(rd()); // mersene twister engine
        uniform_int_distribution<int> distribution(min, max);

        return distribution(generator);
    }

    // generates and returns pseudo random data in a DemandRequest 
    DemandRequest generateRequest(int vehicleId) {
        DemandRequest newDemand;

        newDemand.VehicleId = vehicleId;
        newDemand.DestinationId = getRandomInt(1, NUM_CITIES);
        newDemand.CapacityRange = getRandomInt(MIN_CAPACITY, MAX_CAPACITY);
        newDemand.RemainingRange = getRandomInt(MIN_REMAIN_RANGE, MAX_CAPACITY);

        return newDemand;
    }
public:
    DemandGenerator(const string& fileName, const string& path = "./", int limit = defaultLimit)
    : generationLimit(limit), outputSavePath(path + fileName) {        
        fileOut.open(outputSavePath);
        cout << "creating demand file at: " << outputSavePath << endl;

        if (fileOut.is_open()) {
            for (int vehicleId = 1; vehicleId <= limit; vehicleId++) {
                DemandRequest newDemand = generateRequest(vehicleId);
                fileOut << "[";
                fileOut << newDemand.VehicleId << ",";
                fileOut << newDemand.DestinationId << ",";
                fileOut << newDemand.CapacityRange << ",";
                fileOut << newDemand.RemainingRange;
                fileOut << "]" << endl;
            }

            cout << "successfully created '" << fileName << "' at: " << outputSavePath << endl;
        } else {
            cerr << "error: could not genenerate demand file '" << fileName << "'"
            << endl;
        }
    }

    ~DemandGenerator() {
        if (fileOut.is_open()) {
            fileOut.close();
        }

        cout << "DemandGenerator destructed" << endl;
    }
};


int main() {
    // test 1 - save the output ChargingDemandsTest.txt
    string outputFile = "ChargingDemandsTest.txt";

    // test 2 - save the output ChargingsDemandsTest.txt to below output path
    string outputPath = "C:\\users\\divjoseph\\Desktop\\Dev\\Learning\\C++\\COMP2014_OOP\\src\\assignment-2\\demand\\";

    DemandGenerator dg(
        outputFile,
        outputPath,
        1000
    );

    return 0;
}
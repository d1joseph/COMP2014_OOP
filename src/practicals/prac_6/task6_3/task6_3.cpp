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
#include "../../../assignment-2/Constant.h"

using namespace std;

struct DemandInputFields {
    int VehicleId;
    int DestinationId;
    int CapacityRange;
    int RemainingRange;
};

class DemandGenerator {
private:
    static const int defaultLimit = 100;
    int generationLimit;
    string outputSavePath; // where to save the output text file
    ofstream fileOut; // init an fstream object
public:
    DemandGenerator(const string& fileName, const string& path = "./", int limit = defaultLimit)
    : generationLimit(limit), outputSavePath(path + fileName) {        
        fileOut.open(outputSavePath);
        cout << "opening file at: " << outputSavePath << endl;

        if (fileOut.is_open()) {
            for (int i = 0; i < limit; i++) {
                fileOut << "test line: [" << i + 1 << "]" << endl;
            }
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
        50
    );

    return 0;
}
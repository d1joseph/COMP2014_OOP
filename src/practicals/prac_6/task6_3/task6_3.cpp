/* Author: Dhivyan Joseph
   StudentId: 18225899
   Description: A program to generate demand inputs in the format
   [vehicleId, destinationId, capacityRange, remainRange]
   and saved to a text file at a specified location.

   This class is a prototype for the DemandGenerator in assignment 2
*/

#include <iostream>
#include <string>
#include "../../assignment-2/Constant.h"

struct DemandInputFields {
    int VehicleId;
    int DestinationId;
    int CapacityRange;
    int RemainingRange;
};

class DemandGenerator {
private:
    string outputPath =  "C:Users/dhivj/Dev/Learning/C++/COMP2014_OOP/src/assignment-2/demand/ChargingDemandsSample.txt";
public:
    DemandGenerator(string outputPath, int lineCount) {

    }
};


int main() {
    return 0;
}
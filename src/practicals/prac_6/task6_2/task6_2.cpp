/* Author: Dhivyan Joseph
   StudentId: 18225899
   Description: A program to read an text file input and read line-by-line
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

struct DemandInput {
    int VehicleId;
    int DestinationId;
    int CapacityRange;
    int RemainingRange;
};

class Demand {
private:
    string fileName;
    fstream& file;

    // parse a line into a DemandInput struct
    bool ParseLineToDemandInput(const string& line, DemandInput& input) {
        string lineWithoutBrackets = line.substr(1, line.length() - 2);
        stringstream ss(lineWithoutBrackets);

        char discard;
        if (
            ss >>
            input.VehicleId >> 
            discard >>
            input.DestinationId >> 
            discard >>
            input.CapacityRange >> 
            discard >>
            input.RemainingRange
        ) {return true;}

        return false; // parsing failed
    }

public:
    Demand(string inputFileName, fstream& inputFile) : fileName(inputFileName), file(inputFile) {
        if (!file.is_open()) {
            cerr << "error: unable to open file. Is the path correct? ->" << "'"<< fileName << "'" << endl;
        }
    }

    ~Demand() {
        if (file.is_open()) {
            file.close();
        }
    }
    
    // read the file contents line-by-line 
    vector<DemandInput> ReadLines() {
        vector<DemandInput> demandInputs;
        string line;

        while(getline(file,line)) {
            DemandInput input;
            if (ParseLineToDemandInput(line, input)) {
                demandInputs.push_back(input);
            }
        }

        return demandInputs;
    }

    // get fileName
    const string& getFileName() const {
        return fileName;
    }

};

int main() {
    string filePath = "C:/Users/dhivj/Dev/Learning/C++/COMP2014_OOP/src/assignment-2/demand/ChargingDemandsSample.txt";
    fstream demandFile(filePath);
    Demand *demand = new Demand("ChargingDemandsSample.txt",demandFile);
    vector<DemandInput> demandInputs = demand->ReadLines();
    
    // column headers
    cout << setw(5) << "Vehicle Id" << setw(20) << "Destination Id" << setw(20)
    <<  "Capacity Range" << setw(20) << "Remaining range" << endl;

    // data
    for (const DemandInput& input : demandInputs) {
        cout << setw(5) << input.VehicleId << setw(20) << input.DestinationId << setw(20)
        <<  input.CapacityRange << setw(20) << input.RemainingRange << endl;
    }

    return 0;
}
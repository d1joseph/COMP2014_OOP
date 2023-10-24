#ifndef DEMANDGENERATOR_H_
#define DEMANDGENERATOR_H_

#include "lib/Utilities.h"

class DemandGenerator {
private:
    int Limit = MAX_DEMANDS;
public:
    DemandGenerator() {
        cout << "creating demand file with default limit: " << Limit << endl;
    }

    DemandGenerator(int& customLimit) {
        Limit = customLimit;
        cout << "creating demand file with custom limit: " << Limit << endl;
    }

    void Generate(string& fileName) {
        ofstream demandFile(fileName);

        if (!demandFile.is_open()) {
            cerr << "Unable to open the file.\n";
            return;
        }

        for (int line = 0; line < Limit; line++) {
            int vehicleId = Limit + line;
            int destinationId = GenerateRandomInt(1, NUM_CITIES-1);
            int capacityRange = GenerateRandomInt(MIN_CAPACITY, MAX_CAPACITY);
            int remainRange = GenerateRandomInt(MIN_REMAIN_RANGE, capacityRange-1);

            demandFile << "[" << vehicleId << "," << destinationId << ","
                    << capacityRange << "," << remainRange << "]" << endl;
        }

        cout << "successfully created: " << fileName << endl;

        demandFile.close();
    };
};

#endif // DEMANDGENERATOR_H_

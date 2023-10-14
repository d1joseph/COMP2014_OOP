#ifndef DEMANDGENERATOR_H_
#define DEMANDGENERATOR_H_

class DemandGenerator {
private:
    static const int defaultLimit = 200;
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
    Vehicle generateRequest(int vehicleId) {
        Vehicle newDemand;

        newDemand.vehicleId = vehicleId;
        newDemand.destinationId = getRandomInt(1, NUM_CITIES);
        newDemand.capacityRange = getRandomInt(MIN_CAPACITY, MAX_CAPACITY);
        newDemand.remainingRange = getRandomInt(MIN_REMAIN_RANGE, MAX_CAPACITY);

        return newDemand;
    }
public:
    DemandGenerator(const string& fileName, const string& path = "./", int limit = defaultLimit)
    : generationLimit(limit), outputSavePath(path + fileName) {        
        fileOut.open(outputSavePath);
        cout << "creating demand file at: " << outputSavePath << endl;

        if (fileOut.is_open()) {
            for (int vehicleId = 1; vehicleId <= limit; vehicleId++) {
                Vehicle newDemand = generateRequest(vehicleId);
                fileOut << "[";
                fileOut << newDemand.VehicleId << ",";
                fileOut << newDemand.DestinationId << ",";
                fileOut << newDemand.CapacityRange << ",";
                fileOut << newDemand.RemainingRange;
                fileOut << "]" << endl;
            }
        } else {
            cerr << "error: could not genenerate demand file '" << fileName << "'"
            << endl;
        }

        cout << "successfully created '" << fileName << "' at: " << outputSavePath << endl;
    }

    ~DemandGenerator() {
        if (fileOut.is_open()) {
            fileOut.close();
        }

        cout << "DemandGenerator destructed" << endl;
    }
};

#endif // DEMANDGENERATOR_H_

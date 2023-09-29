#ifndef ROUTE_H_
#define ROUTE_H_

#include "ChargingStation.h"

class Route {
private:
    int start;
    int end;
    vector<ChargingStation> ChargingStations;
public:
    Route(int s, int e) : start(s), end(e) {
        for (int i = 0; i < 12; ++i) {
            ChargingStation station(
                i,
                NAME_MAP[i],
                DISTANCE_MAP[i],
                CHARGERS_MAP[i]
            );
            ChargingStations.push_back(station);
        }
    }

    // Destructor
    ~Route() {}

    const vector<ChargingStation>& getChargingStations() const {
        return ChargingStations;
    }

    void printAllChargingStations() const {
        for (const ChargingStation& station : ChargingStations) {
            station.getAllAttributes(); // Call the method to print attributes
        }
    }
};

#endif // ROUTE_H_
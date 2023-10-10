#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
public:
    int VehicleId;
    int CurrentCityId;
    int DestinationId;
    int CapacityRange;
    int RemainingRange;

    Vehicle() {
        CurrentCityId = 0;
    }

    ~Vehicle() {}
};

#endif // VEHICLE_H_
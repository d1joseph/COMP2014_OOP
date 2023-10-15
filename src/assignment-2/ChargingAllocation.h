#ifndef CHARGINGALLOCATION_H_
#define CHARGINGALLOCATION_H_

class ChargingAllocation {
private:
    vector<Vehicle>* vehicles;
public:
    ChargingAllocation(vector<Vehicle>* vehicles): vehicles(vehicles) {}
    void displayVehicleInfo(const Vehicle& vehicle) const;
};

void ChargingAllocation::displayVehicleInfo(const Vehicle& vehicle) const {
    vehicle.getVehicleInformation();
}

#endif // CHARGINGALLOCATION_H_

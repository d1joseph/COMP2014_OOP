/**
Methods for:
1. Generating a uniqueId to assign to a vehicle, `abc123`
2. Getting the distance between two given charging stations a,b
**/
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "../Vehicle.h"

string GenerateId();
int GenerateRemainingRange();
int GenerateRandomInt(int min, int max);

#endif // UTILITIES_H_
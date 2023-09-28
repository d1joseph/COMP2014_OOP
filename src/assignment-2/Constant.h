#ifndef CONSTANT_H_
#define CONSTANT_H_

#include <string>

using namespace std;

const int DISTANCE_MAP[] = { 0, 57, 60, 83, 86, 99, 115, 62, 74, 87, 106, 62};

const int CHARGERS_MAP[] = { 10, 4, 3, 4, 2, 3, 2, 4, 3, 3, 2, 8};

const string NAME_MAP[] = {"Sydney", "Campbelltown", "Mittagong", "Goulburn",
		"Yass", "Gundagai", "Holbrook",
		"Albury", "Wangaratta", "Euroa", "Wallan", "Melbourne" };

const int NAME_MAP_LENGTH = 12;

const int NUM_CITIES = 12;

const int MIN_DEMANDS = 150;

const int MAX_DEMANDS = 200;

const int MIN_CAPACITY = 350;

const int MAX_CAPACITY = 550;

const int MIN_REMAIN_RANGE = 200;

const int SIMULATION_TIMES = 5000;

#endif /* CONSTANT_H_ */

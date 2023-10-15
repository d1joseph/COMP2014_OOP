#include "Utilities.h"
#include <iostream>
#include <string>

string GenerateId() {
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    const string numbers = "0123456789";

    string uniqueID;

    // Generate three random letters
    for (int i = 0; i < 3; ++i) {
        int randomIndex = std::rand() % letters.size();
        uniqueID += letters[randomIndex];
    }

    // Generate three random numbers
    for (int i = 0; i < 3; ++i) {
        int randomIndex = std::rand() % numbers.size();
        uniqueID += numbers[randomIndex];
    }

    return uniqueID;
}

int GenerateRemainingRange() {
    int remainingRange = std::rand() % MIN_REMAIN_RANGE;
    return remainingRange;
}

int GenerateRandomInt(int min, int max) {
    random_device rd;
    mt19937 generator(rd()); // mersene twister engine
    uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}
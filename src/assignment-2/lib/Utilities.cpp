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
/**
* About: implements Task3_1.cpp in OOP
* Author: 18225899
* Date: 22 August 2023
**/

#include <iostream>

class OneDArray {    
public:
    OneDArray(int declaredSize);
    ~OneDArray();
    void fillArray();
    int search(int target);
    int getSize();
    void printArray();
private:
    int* oneDArray; // pointer to the array
    int size;
    int numberUsed;
};

// OneDArray constructor
OneDArray::OneDArray(int declaredSize) {
    size = declaredSize;
    oneDArray = new int[size];
}

// OneDArray desctructor
OneDArray::~OneDArray() {
    delete[] oneDArray;
}

// fillArray gets n - 1, n = declaredSize integers from user input 
// and populates the oneDArray array propertie with those integers,
// the end of the elements to populate is delimited by the numberUsed.
void OneDArray::fillArray() {
    std::cout << "Enter up to " << size << " non-negative integers.\n"
    << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    std::cin >> next;
    while ((next >= 0) && (index < size)) {
        oneDArray[index] = next;
        index++;
        std::cin >> next;
    }

    numberUsed = index;
}

// search performs a liner search for a given target
// in the oneDArray member and returns the element or -1
// if it was not found.
int OneDArray::search(int target) {
    int index;
    bool found = false;

    for (index = 0; index < size && !found; index++) {
        if (oneDArray[index] == target) {
            found = true;
        }
    }

    if (found) {
        std::cout << "target (" << target << ")" << " at index arr[" << index-1 << "]" << std::endl;
        return index;
    } else {
        std::cout << "target not in list" << std::endl;
        return -1;
    }
}

// getter
int OneDArray::getSize() {
    return size;
}

// output array
void OneDArray::printArray() {
    std::cout << "outputting current elements in array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << oneDArray[i];
    }
    std::cout << std::endl;
}
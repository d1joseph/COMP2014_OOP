/**
* About: implements Task3_1.cpp in OOP
* Author: 18225899
* Date: 22 August 2023
**/
#ifndef ONEDARRAY_H_
#define ONEDARRAY_H_

class OneDArray {    
public:
    OneDArray(int declaredSize);
    ~OneDArray();
    void fillArray();
    int search(int target);
    int getSize();
    void printArray();
private:
    int* oneDArray;
    int size;
    int numberUsed;
};

OneDArray::OneDArray(int declaredSize) {
    size = declaredSize;
    oneDArray = new int[size];
}

OneDArray::~OneDArray() {
    delete[] oneDArray;
}

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

int OneDArray::getSize() {
    return size;
}

void OneDArray::printArray() {
    std::cout << "outputting current elements in array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << oneDArray[i];
    }
    std::cout << std::endl;
}

#endif // ONEDARRAY_H_
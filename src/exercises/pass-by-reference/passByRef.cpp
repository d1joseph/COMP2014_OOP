#include <iostream>

using namespace std;

void One(int first, int& second) {
    first = 17;
    second = first + 1;
}

int main() {
    int j = 4;
    int k = 3;
    One(j, k);
    cout << "j=" << j << ", " << "k=" << k << endl;
};
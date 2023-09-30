//Created by Dongmo
#include <iostream>
using namespace std;

class Counted {
    static int count;
public:
    Counted() {
        cout << "No " << ++count << " object is created \n";
    }
};

int Counted::count = 0;

int main() {
    Counted c1,c2,c3;
    return 0;    
}


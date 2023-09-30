//Created by Dongmo
#include <iostream>
using namespace std;

class Counted {
    static int count;
public:
    Counted() {
        cout << "Counted's ctor is called" << endl;
        cout << "No " << ++count << " object is created \n";
    }

    ~Counted() {
        cout << "Counted's dtor is called" << endl;
    }
};

int Counted::count = 0;

int main() {
    Counted c1,c2,c3;
    Counted *c4 = new Counted;
    delete c4;

    return 0;    
}


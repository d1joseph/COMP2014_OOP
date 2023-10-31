#include <iostream>
#include <string>
#include "SampleClass.h"
using namespace std;

SampleClass::SampleClass()
{
    /*Default constructor*/
    cout << "called constructor 1" << endl;
}

SampleClass::SampleClass(int id, int level):id(id), level(level)
{
    cout << "called constructor 2" << endl;
}

int main()
{   
    string name = "Dhiv";
    SampleClass s1, s2(2,2);
}
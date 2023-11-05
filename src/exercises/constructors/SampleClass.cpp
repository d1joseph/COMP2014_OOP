#include <iostream>
#include <string>
#include "SampleClass.h"
using namespace std;

SampleClass::SampleClass()
{
    /*Default constructor*/
    cout << "called constructor 1" << endl;
}

SampleClass::SampleClass(int id):id(id)
{   
    cout << "called constructor 2" << endl;
    level = id * 2;
}

SampleClass::SampleClass(int id, int level):id(id), level(level)
{
    cout << "called constructor 3" << endl;
}

int SampleClass::getId() const
{
    return id;
}

int SampleClass::getLevel() const
{
    return level;
}

int main()
{   
    string name = "Dhiv";
    SampleClass s1, s2(10), s3(2,2);
    cout << "s1 values: " << s1.getId() << " " << s1.getLevel() << endl;
    cout << "s2 values: " << s2.getId() << " " << s2.getLevel() << endl;
    cout << "s3 values: " << s3.getId() << " " << s3.getLevel() << endl;
}
#ifndef SAMPLE_CLASS_H_
#define SAMPLE_CLASS_H_

class SampleClass {
public:
    SampleClass(); // no args == default constructor
    SampleClass(int, int); // overloading the constructor
private:
    int id;
    int level;
};

#endif // SAMPLE_CLASS_H
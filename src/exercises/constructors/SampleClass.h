#ifndef SAMPLE_CLASS_H_
#define SAMPLE_CLASS_H_

class SampleClass {
public:
    SampleClass(); // no args == default constructor
    SampleClass(int); // 1 overload
    SampleClass(int, int); // 1+ overloads
    int getId() const;
    int getLevel() const;
private:
    int id;
    int level;
};

#endif // SAMPLE_CLASS_H
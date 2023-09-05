class Test {
    int x;
};

class A {
public:
    A() {};
    A(int x, char y):xx(x), yy(y) {};
private:
    int xx;
    int yy;
};


class C {
    // private
    int x;
    int y;
private:
    int z;
};

class D {
public:
    int x;
    int y;
private:
    int z;
};

class foo {
    public:
    void output();
};
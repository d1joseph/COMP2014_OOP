/*
    Overload operators +, -, %, or ==, and more.
*/
#include <iostream>

using namespace std;

class Block
{
private:
    int width;
    int height;
public:
    Block():width(0), height(0){}; // default constructor
    Block(int w, int h): width(w), height(h){};

    // getters
    int getWidth() const
    {
        return width;
    }

    int getHeight() const
    {
        return height;
    }

    // setters
    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }

    // operator overloads
    

};

int main()
{

    return 0;
}
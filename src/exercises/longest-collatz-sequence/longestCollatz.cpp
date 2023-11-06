/*
    Collatz sequence are an interative sequence for all positive integers where:
    n -> n/2 (n is even) or n -> 3n + 1 (n is odd)
*/

#include <vector>
#include <iostream>

using namespace std;

class LongestCollatz
{
private:
    int chainLength;
    unsigned long seed; // first number to start the sequence
    unsigned long current;
public:
    LongestCollatz():chainLength(0), seed(1000000){/* default constructor */}
    LongestCollatz(unsigned long n):chainLength(0){ seed = n; };

    int getChainLength() const
    {   
        cout << "chainLength: " << chainLength << endl;
        return chainLength;
    }

    unsigned long getSeed() const
    {
        cout << "seed: " << seed << endl;
        return seed;
    }

    unsigned long getCurrent() const
    {
        cout << "current: " << current << endl;
        return current;
    }

    LongestCollatz& operator++()
    {
        chainLength++;
        return *this;
    }

    LongestCollatz operator++(int)
    {
        LongestCollatz temp(*this);
        ++(*this);
        return temp;
    }

    LongestCollatz& operator--()
    {
        seed--;
        return *this;
    }

    LongestCollatz operator--(int)
    {
        LongestCollatz temp(*this);
        --(*this);
        return temp;
    }
};

int main()
{
    LongestCollatz lc(1000000); // seed with 1 x 10^6.

    for (int i = lc.getSeed(); i > 1; i--) {
        --lc;
        lc.getSeed();
    }

    return 0;
}
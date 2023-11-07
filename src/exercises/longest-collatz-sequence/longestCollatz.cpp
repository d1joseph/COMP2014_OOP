/*
    Collatz sequence are an interative sequence for all positive integers where:
    n -> n/2 (n is even) or n -> 3n + 1 (n is odd)
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class LongestCollatz
{
private:
    int chainLength; // counter
    unsigned long seed; // first number to start the sequence
public:
    LongestCollatz():chainLength(1), seed(1000000){/* default constructor */}
    LongestCollatz(unsigned long n):chainLength(1){ seed = n; };

    int getChainLength() const
    {   
        // cout << "chainLength: " << chainLength << endl;
        return chainLength;
    }

    unsigned long getSeed() const
    {
        // cout << "seed: " << seed << endl;
        return seed;
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
    // produce a collatz sequence using the seed 13
    LongestCollatz lc(1000000);
    int s = lc.getSeed();
    int end;
    
    end = 1; // sequence ends when i == end
    int i = s; // copy s into i;
    
    // builds the sequence given a seed = s
    while (i != end) {
        lc++; // increment the chainLength counter;

        if (i % 2 != 0) {
            i = (3 * i) + 1; // odd operation
        } else {
            i = i / 2; // even operation
        }

        cout << "n = " << i << endl;
    }
    cout << "senquence created.\n" << "Chain length: " << lc.getChainLength() << endl;

    // TODO: find a seed < 1,000,000 that produces the longest chaing length;

    return 0;
}
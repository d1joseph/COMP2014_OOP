//Program to demonstrate the CDAccount structure type.
#include <cmath>
#include <iostream>

using namespace std;

#include "Account.h"

class DepositAccount : public Account {
public:
    const void test() {
        cout << "\nTest deposit account --- " << endl;
        setAll();

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The balance of deposit at maturity is $"
        << getBalanceAtMaturity() <<" after " << term << " months."<< endl;
    }
};

class LoanAccount: public Account {
public:
    const void test() {
        cout << "\nTest loan account --- " << endl;
        setAll();

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The monthly payment of the loan is $"
        << getMonthlyPayment() <<" for " << term << " months."<< endl;
    }
};

int main( )
{   
    DepositAccount testDepositAccount;
    testDepositAccount.test();
    testDepositAccount.getAll();

    LoanAccount testLoanAccount;
    testLoanAccount.test();
    testLoanAccount.getAll();

    return 0;
}

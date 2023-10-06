#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account {
protected:
    double initialBalance;
    double interestRate; // 
    int term; // months until maturity
public:
    Account(double balance, double rate, int months) {
        initialBalance = balance;
        interestRate = rate;
        term = months;
    };
    
    ~Account() {};
    
    virtual void getAll() {
        cout << "balance ($): " << initialBalance << endl;
        cout << "rate (%): " << interestRate << endl;
        cout << "term: " << term << " months" << endl;
    };

    void setAll() {
        cout << "Enter the amount of initial balance: $";
        cin >> initialBalance;
        cout << "Enter interest rate percent per annual: ";
        cin >> interestRate;
        cout << "Enter the number of months: ";
        cin >> term;
    };

    virtual double getBalanceAtMaturity() {
	    double rateFraction, interest;
	    rateFraction = interestRate/100.0;
	    interest = initialBalance*(rateFraction*(term/12.0));//simple interest
	    double balanceAtMaturity = initialBalance + interest;
        return balanceAtMaturity;
    };

    virtual double getMonthlyPayment() {
	    double rateFraction = interestRate/(12.0*100.0);
	    double payment = initialBalance * (rateFraction + rateFraction / (pow(1+rateFraction,term)-1.0));//simple interest
	    return payment;
    };
};

#endif // ACCOUNT_H_
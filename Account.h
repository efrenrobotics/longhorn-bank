#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    private:
        double balance;
        int numDeposits;
        int numWithdrawals;
        double annualInterestRate;
        double serviceCharge;

    public:
        // Account constructor
        Account(double bal, double interestRate){
            balance = bal;
            annualInterestRate = interestRate;
            numDeposits = 0;
            numWithdrawals = 0;
            serviceCharge = 0;
        }
        // Account destructor
        ~Account(){}
        // deposit function, value parameter which adds to the account balance
        // Increments number of deposits
        virtual void deposit(double val);
        // withdraw function, value parameter which substracts from account balance
        // Incrementes number of withdrawals
        virtual void withdraw(double val) = 0;
        // calculates monthly interest earned, adds interest to balance
        virtual void calcInt();
        // subtracts monthly service charges from balance, calls calcInt(),
        // sets numWithdrawals, numDeposits, and monthly charges to zero
        virtual void monthlyProc() = 0;
};

#endif
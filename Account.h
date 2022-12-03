#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    protected:
        double balance;
        int numDeposits;
        int numWithdrawals;
        double annualInterestRate;
        double serviceCharges;

        double depositTotal;
        double withdrawalTotal;
        double interestAmount;
        double serviceChargesTotal;

    public:
        Account() = default;
        // Account constructor
        Account(double bal, double interestRate) {
            balance = bal;
            annualInterestRate = interestRate;
            numDeposits = 0;
            numWithdrawals = 0;
            serviceCharges = 0;
            depositTotal = 0;
            withdrawalTotal = 0;
            interestAmount = 0;
            serviceChargesTotal = 0;
        }
        // Account destructor
        ~Account(){}
        // deposit function, value parameter which adds to the account balance
        // Increments number of deposits
        virtual void deposit(double val);
        // withdraw function, value parameter which substracts from account balance
        // Incrementes number of withdrawals
        virtual void withdraw(double val);
        // calculates monthly interest earned, adds interest to balance
        virtual void calcInt();
        // subtracts monthly service charges from balance, calls calcInt(),
        // sets numWithdrawals, numDeposits, and monthly charges to zero
        virtual void monthlyProc();

        double getBalance();
        double getDepositTotal();
        double getWithdrawalTotal();
        double getInterest();
        double getServiceCharges();
};

#endif
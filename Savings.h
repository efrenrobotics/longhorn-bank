#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account{
    private:
        // if accounts balance is under 25, then account
        // becomes inactive
        bool status;
        double balance;

    public:
        // use parent constructor
        using Account::Account;

        // 
        void withdraw(double val);
        void deposit(double val);

        // check number of withdrawals, penalty 
        // if it goes above alloted amount
        void monthlyProc();
        // helper, check if the savings acc is active
        bool checkStatus();


}; 

#endif
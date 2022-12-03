#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
    private:
        // if accounts balance is under 25, then account
        // becomes inactive
        bool active;
        const static int MIN_BALANCE = 25;
        const static int NUM_FREE_WITHDRAWALS = 4;

    public:
        Savings(double bal, double interestRate) : Account(bal, interestRate) {
            if (bal < MIN_BALANCE) {
                active = false;
            } else {
                active = true;
            }
        }

        void withdraw(double val);
        void deposit(double val);

        // check number of withdrawals, penalty 
        // if it goes above alloted amount
        void monthlyProc();
}; 

#endif
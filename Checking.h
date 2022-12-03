#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking : public Account {
    private:
        const static int OVERDRAFT_FEE = 15;
        const static int MONTHLY_FEE = 5;

    public:
        Checking(double bal, double interestRate) : Account(bal, interestRate) {}

        // check if balance drops below 0, charge a penalty if it does
        // set to negative balance if penalty can't be paid
        void withdraw(double val);

        // add monthly fee and charge per widthdrawal
        void monthlyProc();
};

#endif
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Savings : public Account{
    private:

    public:
        // use parent constructor
        using Account::Account;
        // check if balance drops below 0, charge a penalty if it does
        // set to negative balance if penalty can't be paid
        void withdraw(double val);

        void deposit(double val);

        // add monthly fee and charge per widthdrawal
        void monthlyProc();
};

#endif
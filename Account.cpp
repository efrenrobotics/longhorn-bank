#include "Account.h"

void Account::deposit(double val) {
    balance += val;
    numDeposits++;
}

void Account::calcInt() {
    double monthlyInterestRate = (annualInterestRate / 12.0);
    double monthlyInterest = balance * monthlyInterestRate;
    balance += monthlyInterest;
}



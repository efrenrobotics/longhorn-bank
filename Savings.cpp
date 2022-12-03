#include "Savings.h"

void Savings::withdraw(double val) {
    if (active) {
        if (balance - val < 0) {
            Account::withdraw(balance);
        } else {
            Account::withdraw(val);
        }
        if (balance < MIN_BALANCE) {
            active = false;
        }
    }
}

void Savings::deposit(double val) {
    Account::deposit(val);
    if (!active && balance >= MIN_BALANCE) {
        active = true;
    }
}

void Savings::monthlyProc() {
    int numChargedWithdrawals = numWithdrawals - NUM_FREE_WITHDRAWALS;
    if (numChargedWithdrawals > 0) {
        serviceCharges = numChargedWithdrawals;
    }
    Account::monthlyProc();
    if (balance < MIN_BALANCE) {
        active = false;
    }
}

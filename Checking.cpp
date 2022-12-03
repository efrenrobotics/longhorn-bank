#include "Checking.h"

void Checking::withdraw(double val) {
    if (balance - val < 0) {
        balance -= OVERDRAFT_FEE;
        withdrawalTotal += OVERDRAFT_FEE;
    } else {
        Account::withdraw(val);
    }
}

void Checking::monthlyProc() {
    serviceCharges = MONTHLY_FEE + (0.1 * numWithdrawals);
    Account::monthlyProc();
}

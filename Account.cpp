#include "Account.h"

void Account::deposit(double val) {
    balance += val;
    numDeposits++;
    depositTotal += val;
}

void Account::withdraw(double val) {
    balance -= val;
    numWithdrawals++;
    withdrawalTotal += val;
}

void Account::calcInt() {
    double monthlyInterestRate = annualInterestRate / 12.0;
    double monthlyInterest = balance * monthlyInterestRate;
    balance += monthlyInterest;
    interestAmount = monthlyInterest;
}

void Account::monthlyProc() {
    serviceChargesTotal = serviceCharges;
    balance -= serviceCharges;
    calcInt();
    numWithdrawals = 0;
    numDeposits = 0;
    serviceCharges = 0;
}

double Account::getBalance() {
    return balance;
}

double Account::getDepositTotal() {
    return depositTotal;
}

double Account::getWithdrawalTotal() {
    return withdrawalTotal;
}

double Account::getInterest() {
    return interestAmount;
}

double Account::getServiceCharges() {
    return serviceChargesTotal;
}

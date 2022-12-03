#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "Account.h"
#include "Checking.h"
#include "Savings.h"

using namespace std;

vector<vector<double>> readTransactions(ifstream &transactionsFile) {
    string input;
    getline(transactionsFile, input);
    string temp;
    stringstream ss(input);
    vector<string> items;
    while (getline(ss, temp, ' ')) {
        items.push_back(temp);
    }
    vector<vector<double>> transactions;
    vector<double> types;
    vector<double> amounts;
    for (int index = 0; index < items.size(); index += 2) {
        string type = items[index];
        double amount = stod(items[index + 1]);
        if (type.compare("D") == 0) {
            types.push_back(1);
        } else if (type.compare("W") == 0) {
            types.push_back(0);
        }
        amounts.push_back(amount);
    }
    transactions.push_back(types);
    transactions.push_back(amounts);
    return transactions;
}

void processTransactions(Account *account, vector<vector<double>> transactions) {
    for (int index = 0; index < transactions[0].size(); index++) {
        double type = transactions[0][index];
        if (type == 0) {
            account->withdraw(transactions[1][index]);
        } else if (type == 1) {
            account->deposit(transactions[1][index]);
        }
    }
    account->monthlyProc();
}

void printTransactions(vector<vector<double>> transactions) {
    cout << "Transactions:" << endl;
    cout << fixed << setprecision(2);
    for (int index = 0; index < transactions[0].size(); index++) {
        double type = transactions[0][index];
        char sign = (type == 1) ? '+' : '-';
        cout << sign << " $" << transactions[1][index] << endl;
    }
}

void printStatistics(double beginBalance, Account *account) {
    cout << endl << "End of Month Summary" << endl;
    cout << "Beginning Balance: $" << beginBalance << endl;
    cout << "Deposit Total Amount: $"  << account->getDepositTotal() << endl;
    cout << "Withdrawal Total Amount: $" << account->getWithdrawalTotal() << endl;
    cout << "Total Interest: $" << account->getInterest() << endl;
    cout << "Service Charge Amount: $" << account->getServiceCharges() << endl;
    cout << "Ending balance: $" << account->getBalance() << endl;
}

int main() {
    ifstream transactionsFile;
    transactionsFile.open("transactions.txt");
    Account *account;
    string input, balanceInput, interestInput;
    getline(transactionsFile, input);
    getline(transactionsFile, balanceInput);
    getline(transactionsFile, interestInput);
    double balance = stod(balanceInput);
    double interestRate = stod(interestInput);
    if (input.compare("Savings") == 0) {
        account = new Savings(balance, interestRate);
    } else if (input.compare("Checking") == 0) {
        account = new Checking(balance, interestRate);
    }
    vector<vector<double>> transactions = readTransactions(transactionsFile);
    processTransactions(account, transactions);
    printTransactions(transactions);
    printStatistics(balance, account);
    delete account;
    return 0;
}

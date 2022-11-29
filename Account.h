


class Account {
    public:
        // Account constructor
        Account(double balance, double interestRate){};
        // Account destructor
        ~Account(){};
        // deposit function, value parameter which adds to the account balance
        // Increments number of deposits
        virtual void deposit(double val);
        // withdraw function, value parameter which substracts from account balance
        // Incrementes number of withdrawals
        virtual void withdraw(double val);
        // calculates monthly interest earned, adds interest to balance
        virtual void calcInt();
};
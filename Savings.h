#include "Account.h"


class Savings : public Account{
    private:
        // if accounts balance is under 25, then account
        // becomes inactive
        bool status;

    public:
        void withdraw(double val);

}; 
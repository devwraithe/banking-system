#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <vector>

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNumber;
    int findAccount(int acctNumber);

public:
    Bank();

    void createAccount();
    void displayAccountInfo();
    void depositFunds();
    void withdrawFunds();
    void deleteAccount();
    void displayAllAccounts();
};

#endif // BANK_H
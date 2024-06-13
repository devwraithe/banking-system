#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    int accountNumber;
    std::string accountHolderName;
    double balance;

    Account(int acctNumber, std::string acctHolderName, double initialBalance);

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H
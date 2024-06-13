#include "../include/account.h"
#include <iostream>

using namespace std;

Account::Account(int acctNumber, string acctHolderName, double initialBalance) {
    accountNumber = acctNumber;
    accountHolderName = acctHolderName;
    balance = initialBalance;
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Amount deposited successfully! New balance: $" << balance << endl;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Amount withdrawn successfully! New balance: $" << balance << endl;
        return true;
    } else {
        cout << "Insufficient funds! Current balance: $" << balance << endl;
        return false;
    }
}
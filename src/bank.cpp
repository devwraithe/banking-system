#include "../include/bank.h"
#include <iostream>

using namespace std;

Bank::Bank() : nextAccountNumber(1) {}

int Bank::findAccount(int acctNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].accountNumber == acctNumber) {
            return i;
        }
    }
    return -1;
}

void Bank::createAccount() {
    string name;
    double initialDeposit;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;

    Account newAccount(nextAccountNumber++, name, initialDeposit);
    accounts.push_back(newAccount);

    cout << "Account created successfully! Your account number is " << newAccount.accountNumber << endl;
}

void Bank::displayAccountInfo() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    int index = findAccount(acctNumber);

    if (index != -1) {
        const Account& account = accounts[index];
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Account Holder Name: " << account.accountHolderName << endl;
        cout << "Balance: $" << account.balance << endl;
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::depositFunds() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    int index = findAccount(acctNumber);

    if (index != -1) {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        accounts[index].deposit(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::withdrawFunds() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    int index = findAccount(acctNumber);

    if (index != -1) {
        double amount;
        cout << "Enter withdrawal amount: ";
            cin >> amount;
            accounts[index].withdraw(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::deleteAccount() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    int index = findAccount(acctNumber);

    if (index != -1) {
        accounts.erase(accounts.begin() + index);
        cout << "Account deleted successfully!" << endl;
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::displayAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found." << endl;
        return;
    }

    cout << "List of all accounts:" << endl;
    for (const auto& account : accounts) {
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Account Holder Name: " << account.accountHolderName << endl;
        cout << "Balance: $" << account.balance << endl;
        cout << "-----------------------------" << endl;
    }
}
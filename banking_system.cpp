#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Account {
    public:
        int accountNumber;
        string accountHolderName;
        double balance;

    Account(int acctNumber, string acctHolderName, double initialBalance) {
        accountNumber = acctNumber;
        accountHolderName = acctHolderName;
        balance = initialBalance;
    }


    void deposit(unsigned int amount) {
        balance += amount;
        cout << "Amount deposited successfully! New balance: $" << balance << endl;
    }
};

vector<Account> accounts;
int nextAccountNumber;

void createAccount() {
    string name;
    double initialDeposit;

    cout << "Enter account holder name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter initial deposit amount: ";
    cin >>  initialDeposit;

    Account newAccount(nextAccountNumber++, name, initialDeposit);
    accounts.push_back(newAccount);

    cout << "Account created successfully! Your account number is " << newAccount.accountNumber << endl;
}

void displayAccountInfo() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    bool found = false;

    for (size_t i = 0; i < accounts.size(); ++i) {
        const Account& account = accounts[i];
        if (account.accountNumber == acctNumber) {
            cout << "Account Number: " << account.accountNumber << endl;
            cout << "Account Holder Name: " << account.accountHolderName << endl;
            cout << "Balance: $" << account.balance << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found!" << endl;
    }
}

void displayAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found." << endl;
        return;
    }

    cout << "List of all accounts:" << endl;
    for (size_t i = 0; i < accounts.size(); ++i) {
        const Account& account = accounts[i];
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Account Holder Name: " << account.accountHolderName << endl;
        cout << "Balance: $" << account.balance << endl;
        cout << "-----------------------------" << endl;
    }
}

// Find a particular account
int findAccount(int acctNummber) {
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].accountNumber == acctNummber) {
            return i;
        }
    }
    return -1;
}


void depositFunds() {
    int acctNumber;
    cout << "Enter account number: ";
    cin >> acctNumber;

    int index = findAccount(acctNumber);

    if(index != -1) {
        unsigned int amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        accounts[index].deposit(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

// Delete account based on account number
void deleteAccount() {
    int acctNumber;
    cout << "Enter your account number: ";
    cin >> acctNumber;

    // Find the acccount index in the vector i.e accounts list
    int index = findAccount(acctNumber);

    // If account is found, delete it
    if(index != -1) {
        accounts.erase(accounts.begin() + index);
        cout << "Account deleted successfully!" << endl;
    }
    else {
        // If account is not found, notify the user
        cout << "Account not found!" << endl;
    }
}

int main() {
    
    int choice;

    while (true) {
        cout << "C++ Microfinance Bank" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. Display Account Info" << endl;
        cout << "3. Deposit Funds" << endl;
        cout << "4. Withdraw Funds" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Display All Accounts" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        cout << "Your choice: " << choice << endl;

        switch (choice) {
            case 1:
                createAccount();
                break; 
            case 2:
                displayAccountInfo();
                break;
            case 3:
                depositFunds();
                break;
            case 4:
                cout << "Withdraw funds is coming soon!" << endl;
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                displayAllAccounts();
                break;
            case 7:
                cout << "Thank you for using C++ Microfinance Bank. Have a nice day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

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

int main() {
    int choice;

    while (true) {
        cout << "C++ Microfinance Bank" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. Display Account Info" << endl;
        cout << "3. Deposit Funds" << endl;
        cout << "4. Withdraw Funds" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        cout << "Your choice: " << choice << endl;

        switch (choice) {
            case 1:
                createAccount();
                break; 
            case 2:
                cout << "Show account information is coming soon!" << endl;
                break;
            case 3:
                cout << "Deposit funds is coming soon!" << endl;
                break;
            case 4:
                cout << "Withdraw funds is coming soon!" << endl;
                break;
            case 5:
                cout << "Delete account is coming soon!" << endl;
                break;
            case 6:
                cout << "Thank you for using C++ Microfinance Bank. Have a nice day!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

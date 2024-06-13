#include <iostream>
#include "../include/account.h"
#include "../include/bank.h"

using namespace std;

int main() {
    Bank bank;
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

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.displayAccountInfo();
                break;
            case 3:
                bank.depositFunds();
                break;
            case 4:
                bank.withdrawFunds();
                break;
            case 5:
                bank.deleteAccount();
                break;
            case 6:
                bank.displayAllAccounts();
                break;
            case 7:
                cout << "Thank you for using C++ Microfinance Bank. Have a nice day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        return 0;

    }
}
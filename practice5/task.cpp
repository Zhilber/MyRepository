#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    string ownerName;
    double balance;
};

void createAccount(BankAccount& account, const string& owner, double initialBalance) {
    account.ownerName = owner;
    account.balance = initialBalance;
}

void deposit(BankAccount& account, double amount) {
    account.balance += amount;
    cout << "Deposit of " << amount << " was successful. Current balance: " << account.balance << endl;
}

void withdraw(BankAccount& account, double amount) {
    if (amount > account.balance) {
        cout << "Insufficient funds for withdrawal!" << endl;
    }
    else {
        account.balance -= amount;
        cout << "Withdrawal of " << amount << " was successful. Current balance: " << account.balance << endl;
    }
}

void displayAccounts(BankAccount accounts[], int size) {
    cout << "Account information:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Owner: " << accounts[i].ownerName << ", Balance: " << accounts[i].balance << endl;
    }
}

int main() {
    const int MAX_ACCOUNTS = 10;
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;

    int choice;
    string owner;
    double amount;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create a new account\n";
        cout << "2. Deposit into an account\n";
        cout << "3. Withdraw from an account\n";
        cout << "4. Display account information\n";
        cout << "5. Exit\n";
        cout << "Choose an action: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount < MAX_ACCOUNTS) {
                cout << "Enter owner's name: ";
                cin.ignore();
                getline(cin, owner);
                cout << "Enter initial balance: ";
                cin >> amount;
                createAccount(accounts[accountCount], owner, amount);
                ++accountCount;
                cout << "Account created successfully!\n";
            }
            else {
                cout << "Maximum number of accounts reached!\n";
            }
        }
        else if (choice == 2) {
            cout << "Enter account number for deposit (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accounts[index], amount);
            }
            else {
                cout << "Invalid account number!\n";
            }
        }
        else if (choice == 3) {
            cout << "Enter account number for withdrawal (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accounts[index], amount);
            }
            else {
                cout << "Invalid account number!\n";
            }
        }
        else if (choice == 4) {
            displayAccounts(accounts, accountCount);
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

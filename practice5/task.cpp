#include <iostream>
#include <string>
using namespace std;

// ��������� ��� ����������� �������
struct BankAccount {
    string ownerName;  // ��'� ��������
    double balance;    // ������ �������
};

// ������� ��� ��������� �������
void createAccount(BankAccount& account, const string& owner, double initialBalance) {
    account.ownerName = owner;
    account.balance = initialBalance;
}

// ������� ��� ���������� �������
void deposit(BankAccount& account, double amount) {
    account.balance += amount;
    cout << "���������� ������� �� ���� " << amount << " ������ ���������. �������� ������: " << account.balance << endl;
}

// ������� ��� ������ ����� � �������
void withdraw(BankAccount& account, double amount) {
    if (amount > account.balance) {
        cout << "����������� ����� ��� ������!" << endl;
    }
    else {
        account.balance -= amount;
        cout << "������ ����� �� ���� " << amount << " ������ ���������. �������� ������: " << account.balance << endl;
    }
}

// ������� ��� ��������� ���������� ��� �� �������
void displayAccounts(BankAccount accounts[], int size) {
    cout << "���������� ��� �� �������:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "�������: " << accounts[i].ownerName << ", ������: " << accounts[i].balance << endl;
    }
}

int main() {
    const int MAX_ACCOUNTS = 10; // ����������� ������� �������
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;

    int choice;
    string owner;
    double amount;

    while (true) {
        cout << "\n����:\n";
        cout << "1. �������� ����� �������\n";
        cout << "2. ��������� �������\n";
        cout << "3. ����� ����� � �������\n";
        cout << "4. ������� ���������� ��� �������\n";
        cout << "5. �����\n";
        cout << "������� ��: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount < MAX_ACCOUNTS) {
                cout << "������ ��'� ��������: ";
                cin.ignore(); // ������� �����
                getline(cin, owner);
                cout << "������ ���������� ������: ";
                cin >> amount;
                createAccount(accounts[accountCount], owner, amount);
                ++accountCount;
                cout << "������� ������ ��������!\n";
            }
            else {
                cout << "��������� ������������� ���� �������!\n";
            }
        }
        else if (choice == 2) {
            cout << "������ ����� ������� ��� ���������� (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "������ ���� ��� ����������: ";
                cin >> amount;
                deposit(accounts[index], amount);
            }
            else {
                cout << "������� ����� �������!\n";
            }
        }
        else if (choice == 3) {
            cout << "������ ����� ������� ��� ������ ����� (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "������ ���� ��� ������: ";
                cin >> amount;
                withdraw(accounts[index], amount);
            }
            else {
                cout << "������� ����� �������!\n";
            }
        }
        else if (choice == 4) {
            displayAccounts(accounts, accountCount);
        }
        else if (choice == 5) {
            cout << "���������� ��������...\n";
            break;
        }
        else {
            cout << "������� ����! ��������� �� ���.\n";
        }
    }

    return 0;
}

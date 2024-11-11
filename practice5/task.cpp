#include <iostream>
#include <string>
using namespace std;

// Структура для банківського рахунку
struct BankAccount {
    string ownerName;  // ім'я власника
    double balance;    // баланс рахунку
};

// Функція для створення рахунку
void createAccount(BankAccount& account, const string& owner, double initialBalance) {
    account.ownerName = owner;
    account.balance = initialBalance;
}

// Функція для поповнення рахунку
void deposit(BankAccount& account, double amount) {
    account.balance += amount;
    cout << "Поповнення рахунку на суму " << amount << " успішно завершено. Поточний баланс: " << account.balance << endl;
}

// Функція для зняття коштів з рахунку
void withdraw(BankAccount& account, double amount) {
    if (amount > account.balance) {
        cout << "Недостатньо коштів для зняття!" << endl;
    }
    else {
        account.balance -= amount;
        cout << "Зняття коштів на суму " << amount << " успішно завершено. Поточний баланс: " << account.balance << endl;
    }
}

// Функція для виведення інформації про всі рахунки
void displayAccounts(BankAccount accounts[], int size) {
    cout << "Інформація про всі рахунки:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Власник: " << accounts[i].ownerName << ", Баланс: " << accounts[i].balance << endl;
    }
}

int main() {
    const int MAX_ACCOUNTS = 10; // Максимальна кількість рахунків
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;

    int choice;
    string owner;
    double amount;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Створити новий рахунок\n";
        cout << "2. Поповнити рахунок\n";
        cout << "3. Зняти кошти з рахунку\n";
        cout << "4. Вивести інформацію про рахунки\n";
        cout << "5. Вийти\n";
        cout << "Виберіть дію: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount < MAX_ACCOUNTS) {
                cout << "Введіть ім'я власника: ";
                cin.ignore(); // Очищаємо буфер
                getline(cin, owner);
                cout << "Введіть початковий баланс: ";
                cin >> amount;
                createAccount(accounts[accountCount], owner, amount);
                ++accountCount;
                cout << "Рахунок успішно створено!\n";
            }
            else {
                cout << "Досягнуто максимального ліміту рахунків!\n";
            }
        }
        else if (choice == 2) {
            cout << "Введіть номер рахунку для поповнення (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "Введіть суму для поповнення: ";
                cin >> amount;
                deposit(accounts[index], amount);
            }
            else {
                cout << "Невірний номер рахунку!\n";
            }
        }
        else if (choice == 3) {
            cout << "Введіть номер рахунку для зняття коштів (0-" << accountCount - 1 << "): ";
            int index;
            cin >> index;
            if (index >= 0 && index < accountCount) {
                cout << "Введіть суму для зняття: ";
                cin >> amount;
                withdraw(accounts[index], amount);
            }
            else {
                cout << "Невірний номер рахунку!\n";
            }
        }
        else if (choice == 4) {
            displayAccounts(accounts, accountCount);
        }
        else if (choice == 5) {
            cout << "Завершення програми...\n";
            break;
        }
        else {
            cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    }

    return 0;
}

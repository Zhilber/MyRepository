#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

string itemNames[MAX_ITEMS];
int itemQuantities[MAX_ITEMS];
double itemPrices[MAX_ITEMS];
int itemCount = 0;

void addItem(const string& name, int quantity, double price) {
    if (itemCount < MAX_ITEMS) {
        itemNames[itemCount] = name;
        itemQuantities[itemCount] = quantity;
        itemPrices[itemCount] = price;
        itemCount++;
        cout << "Товар '" << name << "' успішно додано на склад.\n";
    }
    else {
        cout << "Склад заповнений, не можна додати новий товар.\n";
    }
}

void removeItem(const string& name) {
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (itemNames[i] == name) {
            for (int j = i; j < itemCount - 1; ++j) {
                itemNames[j] = itemNames[j + 1];
                itemQuantities[j] = itemQuantities[j + 1];
                itemPrices[j] = itemPrices[j + 1];
            }
            itemCount--;
            found = true;
            cout << "Товар '" << name << "' успішно видалено зі складу.\n";
            break;
        }
    }
    if (!found) {
        cout << "Товар з назвою '" << name << "' не знайдено.\n";
    }
}

void updateQuantity(const string& name, int newQuantity) {
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (itemNames[i] == name) {
            itemQuantities[i] = newQuantity;
            found = true;
            cout << "Кількість товару '" << name << "' оновлено до " << newQuantity << ".\n";
            break;
        }
    }
    if (!found) {
        cout << "Товар з назвою '" << name << "' не знайдено.\n";
    }
}

void displayItems() {
    if (itemCount == 0) {
        cout << "На складі немає товарів.\n";
        return;
    }
    cout << "\nСписок товарів на складі:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "Назва: " << itemNames[i]
            << ", Кількість: " << itemQuantities[i]
            << ", Ціна: " << itemPrices[i]
            << ", Вартість: " << itemQuantities[i] * itemPrices[i] << endl;
    }
}

void calculateTotalValue() {
    double totalValue = 0;
    for (int i = 0; i < itemCount; ++i) {
        totalValue += itemQuantities[i] * itemPrices[i];
    }
    cout << "Загальна вартість товарів на складі: " << totalValue << endl;
}

int main() {
    int choice;
    string name;
    int quantity;
    double price;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати товар\n";
        cout << "2. Видалити товар\n";
        cout << "3. Оновити кількість товару\n";
        cout << "4. Показати всі товари\n";
        cout << "5. Розрахувати загальну вартість товарів\n";
        cout << "6. Вийти\n";
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть назву товару: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введіть кількість товару: ";
            cin >> quantity;
            cout << "Введіть ціну товару: ";
            cin >> price;
            addItem(name, quantity, price);
            break;
        case 2:
            cout << "Введіть назву товару для видалення: ";
            cin.ignore();
            getline(cin, name);
            removeItem(name);
            break;
        case 3:
            cout << "Введіть назву товару для оновлення кількості: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введіть нову кількість товару: ";
            cin >> quantity;
            updateQuantity(name, quantity);
            break;
        case 4:
            displayItems();
            break;
        case 5:
            calculateTotalValue();
            break;
        case 6:
            cout << "Завершення програми...\n";
            return 0;
        default:
            cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    }

    return 0;
}

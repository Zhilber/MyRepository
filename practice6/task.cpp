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
        cout << "����� '" << name << "' ������ ������ �� �����.\n";
    }
    else {
        cout << "����� ����������, �� ����� ������ ����� �����.\n";
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
            cout << "����� '" << name << "' ������ �������� � ������.\n";
            break;
        }
    }
    if (!found) {
        cout << "����� � ������ '" << name << "' �� ��������.\n";
    }
}

void updateQuantity(const string& name, int newQuantity) {
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (itemNames[i] == name) {
            itemQuantities[i] = newQuantity;
            found = true;
            cout << "ʳ������ ������ '" << name << "' �������� �� " << newQuantity << ".\n";
            break;
        }
    }
    if (!found) {
        cout << "����� � ������ '" << name << "' �� ��������.\n";
    }
}

void displayItems() {
    if (itemCount == 0) {
        cout << "�� ����� ���� ������.\n";
        return;
    }
    cout << "\n������ ������ �� �����:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "�����: " << itemNames[i]
            << ", ʳ������: " << itemQuantities[i]
            << ", ֳ��: " << itemPrices[i]
            << ", �������: " << itemQuantities[i] * itemPrices[i] << endl;
    }
}

void calculateTotalValue() {
    double totalValue = 0;
    for (int i = 0; i < itemCount; ++i) {
        totalValue += itemQuantities[i] * itemPrices[i];
    }
    cout << "�������� ������� ������ �� �����: " << totalValue << endl;
}

int main() {
    int choice;
    string name;
    int quantity;
    double price;

    while (true) {
        cout << "\n����:\n";
        cout << "1. ������ �����\n";
        cout << "2. �������� �����\n";
        cout << "3. ������� ������� ������\n";
        cout << "4. �������� �� ������\n";
        cout << "5. ����������� �������� ������� ������\n";
        cout << "6. �����\n";
        cout << "������� ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ����� ������: ";
            cin.ignore();
            getline(cin, name);
            cout << "������ ������� ������: ";
            cin >> quantity;
            cout << "������ ���� ������: ";
            cin >> price;
            addItem(name, quantity, price);
            break;
        case 2:
            cout << "������ ����� ������ ��� ���������: ";
            cin.ignore();
            getline(cin, name);
            removeItem(name);
            break;
        case 3:
            cout << "������ ����� ������ ��� ��������� �������: ";
            cin.ignore();
            getline(cin, name);
            cout << "������ ���� ������� ������: ";
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
            cout << "���������� ��������...\n";
            return 0;
        default:
            cout << "������� ����! ��������� �� ���.\n";
        }
    }

    return 0;
}

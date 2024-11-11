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
        cout << "Item '" << name << "' successfully added to the stock.\n";
    }
    else {
        cout << "Stock is full, cannot add a new item.\n";
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
            cout << "Item '" << name << "' successfully removed from the stock.\n";
            break;
        }
    }
    if (!found) {
        cout << "Item with the name '" << name << "' not found.\n";
    }
}

void updateQuantity(const string& name, int newQuantity) {
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (itemNames[i] == name) {
            itemQuantities[i] = newQuantity;
            found = true;
            cout << "The quantity of item '" << name << "' updated to " << newQuantity << ".\n";
            break;
        }
    }
    if (!found) {
        cout << "Item with the name '" << name << "' not found.\n";
    }
}

void displayItems() {
    if (itemCount == 0) {
        cout << "No items in stock.\n";
        return;
    }
    cout << "\nList of items in stock:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "Name: " << itemNames[i]
            << ", Quantity: " << itemQuantities[i]
            << ", Price: " << itemPrices[i]
            << ", Value: " << itemQuantities[i] * itemPrices[i] << endl;
    }
}

void calculateTotalValue() {
    double totalValue = 0;
    for (int i = 0; i < itemCount; ++i) {
        totalValue += itemQuantities[i] * itemPrices[i];
    }
    cout << "Total value of items in stock: " << totalValue << endl;
}

int main() {
    int choice;
    string name;
    int quantity;
    double price;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Update item quantity\n";
        cout << "4. Show all items\n";
        cout << "5. Calculate total value of items\n";
        cout << "6. Exit\n";
        cout << "Choose an action: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter item quantity: ";
            cin >> quantity;
            cout << "Enter item price: ";
            cin >> price;
            addItem(name, quantity, price);
            break;
        case 2:
            cout << "Enter item name to remove: ";
            cin.ignore();
            getline(cin, name);
            removeItem(name);
            break;
        case 3:
            cout << "Enter item name to update quantity: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new item quantity: ";
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
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

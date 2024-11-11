#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введіть перше ціле число: ";
    cin >> a;
    cout << "Введіть друге ціле число: ";
    cin >> b;

    cout << "Адреса змінної a: " << &a << endl;
    cout << "Адреса змінної b: " << &b << endl;

    if (a > b) {
        swap(a, b);
    }

    for (int i = a; i <= b; ++i) {
        cout << -i << " ";
    }

    cout << endl;
    return 0;
}

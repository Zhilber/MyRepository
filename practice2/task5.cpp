#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter the first integer: ";
    cin >> a;
    cout << "Enter the second integer: ";
    cin >> b;

    cout << "Address of variable a: " << &a << endl;
    cout << "Address of variable b: " << &b << endl;

    if (a > b) {
        swap(a, b);
    }

    for (int i = a; i <= b; ++i) {
        cout << -i << " ";
    }

    cout << endl;
    return 0;
}

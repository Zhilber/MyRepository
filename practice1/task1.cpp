#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Enter first side: ";
    cin >> a;

    cout << "Enter second side: ";
    cin >> b;

    cout << "s = "<< a * b << endl;
    cout << "p = " << 2 * (a + b);

    cout << endl << &a << endl << &b;
}

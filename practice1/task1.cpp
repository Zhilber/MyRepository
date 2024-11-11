#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Enter length: ";
    cin >> a;

    cout << "Enter width: ";
    cin >> b;

    double amount1 = a * b;
    double amount2 = 2 * (a + b);

    cout << "s = "<< amount1 << endl;
    cout << "p = " << amount2 << endl << endl;

    double sum = amount1 + amount2;
    double difference = amount1 - amount2;
    double dlnna = amount1 / amount2;

    cout << "Amount (+): " << sum << endl;
    cout << "difference (-): " << difference << endl;
    cout << "dilation (/):" << dlnna << endl << endl;

    cout << "Address of a: " << &a << endl;
    cout << "Address of amount1: " << &amount1 << endl;
    cout << "Address of amount2: " << &amount2 << endl;
    cout << "Address of sum: " << &sum << endl;
    cout << "Address of difference: " << &difference << endl;
    cout << "Address of dlnna: " << &dlnna << endl;


    return 0;
}
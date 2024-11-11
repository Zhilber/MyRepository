#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    cout << "Swap by value (inside function): a = " << a << ", b = " << b << "\n";
}

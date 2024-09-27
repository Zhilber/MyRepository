#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Enter number to /7" << endl;
    cin >> a;

    cout << a % 7 << endl;

    int num1, num2;
    cout << "Enter first and second number" << endl;
    cin >> num1 >> num2;

    if(num1 % num2 == 0) {
        cout << "No remainder" << endl;
    }
    else {
        cout << "Has remainder" << endl;
    }

    if(num1 % 2 == 0) {
        cout << "First number is even" << endl;
    }
    else {
        cout << "First number isn't even" << endl;
    }

    if(num2 % 2 == 0) {
        cout << "Second number is even" << endl;
    }
    else {
        cout << "Second number isn't even" << endl;
    }
}


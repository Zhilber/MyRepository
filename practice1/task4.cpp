#include <iostream>

using namespace std;

int main() {
    int age;
    int salary = 0;
    cout << "Enter your age: ";
    cin >> age;
    if (age >= 20) {
        cout << "Enter your salary: ";
        cin >> salary;

    }
    else {
        cout << "You are not suitable" << endl;
        return -1;
    }

    if (salary >= 400 && salary <= 1000) {
        cout << "We will consider your position" << endl;
    }
    else {
        cout << "You are not suitable" << endl;
    return -1;
    }
    cout << "Your age: " << age <<endl <<  "Your salary: " << salary;
}
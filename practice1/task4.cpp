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
        cout << "We will consider your position" << endl << endl;
    }
    else {
        cout << "You are not suitable" << endl << endl;

        return -1;
    }
    string ft_and_lt_name;

    cout << "Enter your first and last name: ";
    cin >> ft_and_lt_name;

    string position;

    cout << "Enter position: ";
    cin >> position;

    //Виведення інформації

    cout << endl << "Your name: " << ft_and_lt_name << endl;
    cout << "Your age: " << age << endl;
    cout << "Your position: " << position << endl;
    cout << "Your selary" << salary << endl;
}
#include <iostream>

using namespace std;

int main() {
    int grade;
    cout << "Enter your grade: ";
    cin >> grade;

    if (grade <= 60) {
        cout << "Unsatisfactory (F)" << endl;
    }

    if (grade > 60 && grade <= 69) {
        cout << "Satisfactory (C)" << endl;
    }

    if (grade >= 70 && grade <= 89) {
        cout << "Good (B)" << endl;
    }

    if (grade >= 90 && grade < 100) {
        cout << "Excellent (A)" << endl;
    }
}
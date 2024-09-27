#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Enter the number:";
    cin >> a;
    cout <<"Before prefix-Decrement: " << a << endl;
    cout << "After: " << --a << endl;

    int b;
    cout << "Enter the number: ";
    cin >> b;
    cout <<"Before prefix-Increment: " << b << endl;
    cout << "After: " <<  ++b << endl;


    int post1;
    cout << "Enter the number: ";
    cin >> post1;
    cout <<"Before postfix-Decrement : " << post1 << endl;
    cout << "After : " << post1-- << endl;

    int post2;
    cout << "Enter the number: ";
    cin >> post2;
    cout <<"Before postfix-Increment: " << post2 << endl;
    cout << "After: " <<  post2++;
}
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "������ ����� ���� �����: ";
    cin >> a;
    cout << "������ ����� ���� �����: ";
    cin >> b;

    cout << "������ ����� a: " << &a << endl;
    cout << "������ ����� b: " << &b << endl;

    if (a > b) {
        swap(a, b);
    }

    for (int i = a; i <= b; ++i) {
        cout << -i << " ";
    }

    cout << endl;
    return 0;
}

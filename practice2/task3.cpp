#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "������ ������ ����������: ";
    cin >> height;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int N, sumEven = 0, sumOdd = 0, sumTotal = 0;

    cout << "������ ����� N: ";
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        sumTotal += i;
        if (i % 2 == 0) {
            cout << i << " ";
            sumEven += i;
        }
        else {
            sumOdd += i;
        }
    }

    cout << "\n���� ������ �����: " << sumEven << endl;
    cout << "���� �������� �����: " << sumOdd << endl;
    cout << "�������� ���� �����: " << sumTotal << endl;

    double result = (sumEven + sumOdd + sumTotal) / 2.0;
    cout << "��������� (���� ��� ���, ������� �� 2): " << result << endl;

    return 0;
}

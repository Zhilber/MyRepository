#include <iostream>
using namespace std;

int main() {
    int year1, year2;
    int countYears = 0, countEveryTenth = 0;

    cout << "������ ������ ��: ";
    cin >> year1;
    cout << "������ ������ ��: ";
    cin >> year2;

    if (year1 > year2) {
        swap(year1, year2);
    }

    if (year2 - year1 > 100) {
        cout << "ʳ������ ���� ����� 100, ����� � ��������." << endl;
        return 0;
    }

    for (int year = year1; year <= year2; ++year) {
        countYears++;
        if (countYears % 10 == 0) {
            countEveryTenth++;
        }
        cout << year << " ";
    }

    cout << "\nʳ������ ����: " << countYears << endl;
    cout << "ʳ������ ������� �������� ����: " << countEveryTenth << endl;

    return 0;
}

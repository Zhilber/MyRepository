#include <iostream>
using namespace std;

int main() {
    int year1, year2;
    int countYears = 0, countEveryTenth = 0;

    cout << "Введіть перший рік: ";
    cin >> year1;
    cout << "Введіть другий рік: ";
    cin >> year2;

    if (year1 > year2) {
        swap(year1, year2);
    }

    if (year2 - year1 > 100) {
        cout << "Кількість років більше 100, вихід з програми." << endl;
        return 0;
    }

    for (int year = year1; year <= year2; ++year) {
        countYears++;
        if (countYears % 10 == 0) {
            countEveryTenth++;
        }
        cout << year << " ";
    }

    cout << "\nКількість років: " << countYears << endl;
    cout << "Кількість кожного десятого року: " << countEveryTenth << endl;

    return 0;
}

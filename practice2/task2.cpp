#include <iostream>
using namespace std;

int main() {
    int year1, year2;
    int countYears = 0, countEveryTenth = 0;

    cout << "Enter the first year: ";
    cin >> year1;
    cout << "Enter the second year: ";
    cin >> year2;

    if (year1 > year2) {
        swap(year1, year2);
    }

    if (year2 - year1 > 100) {
        cout << "The number of years is greater than 100, exiting the program." << endl;
        return 0;
    }

    for (int year = year1; year <= year2; ++year) {
        countYears++;
        if (countYears % 10 == 0) {
            countEveryTenth++;
        }
        cout << year << " ";
    }

    cout << "\nNumber of years: " << countYears << endl;
    cout << "Number of every tenth year: " << countEveryTenth << endl;

    return 0;
}

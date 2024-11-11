#include <iostream>
using namespace std;

int main() {
    int N, sumEven = 0, sumOdd = 0, sumTotal = 0;

    cout << "Введіть число N: ";
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

    cout << "\nСума парних чисел: " << sumEven << endl;
    cout << "Сума непарних чисел: " << sumOdd << endl;
    cout << "Загальна сума чисел: " << sumTotal << endl;

    double result = (sumEven + sumOdd + sumTotal) / 2.0;
    cout << "Результат (сума всіх сум, поділена на 2): " << result << endl;

    return 0;
}

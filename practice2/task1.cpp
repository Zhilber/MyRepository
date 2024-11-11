#include <iostream>
using namespace std;

int main() {
    int N, sumEven = 0, sumOdd = 0, sumTotal = 0;

    cout << "Enter the number N: ";
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

    cout << "\nSum of even numbers: " << sumEven << endl;
    cout << "Sum of odd numbers: " << sumOdd << endl;
    cout << "Total sum of numbers: " << sumTotal << endl;

    double result = (sumEven + sumOdd + sumTotal) / 2.0;
    cout << "Result (sum of all sums divided by 2): " << result << endl;

    return 0;
}

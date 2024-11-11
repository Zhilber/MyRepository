#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "¬вед≥ть число N: ";
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min(const int& a, const int& b) {
    return (a < b) ? a : b;
}

int main() {
    int x = 5, y = 10;
    int minValueByValue = min(x, y);
    int minValueByReference = min(x, y);
    cout << "Min by value: " << minValueByValue << "\n";
    cout << "Min by reference: " << minValueByReference << "\n";
    return 0;
}

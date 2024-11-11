#include <iostream>
using namespace std;

void factorial(int n, int& result) {
    if (n <= 1) {
        result = 1;
    }
    else {
        int temp;
        factorial(n - 1, temp);
        result = n * temp;
    }
}

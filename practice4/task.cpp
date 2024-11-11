#include <iostream>
using namespace std;

// Функція, що копіює значення з однієї змінної в іншу
void copyValue(int* source, int* destination) {
    *destination = *source;
}

// Функція, що рахує парні та непарні числа
void countEvenOdd(int* a, int* b, int* c, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    if (*a % 2 == 0) (*evenCount)++;
    else (*oddCount)++;
    if (*b % 2 == 0) (*evenCount)++;
    else (*oddCount)++;
    if (*c % 2 == 0) (*evenCount)++;
    else (*oddCount)++;
}

// Функція, що множить два числа і зберігає результат через вказівник
void multiply(int* a, int* b, int* result) {
    *result = (*a) * (*b);
}

// Функція, що змінює значення двох змінних місцями без використання тимчасової змінної
void swapWithoutTemp(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Функція, що знаходить мінімальне і максимальне значення з трьох чисел
void findMinMax(int* a, int* b, int* c, int* min, int* max) {
    *min = *a;
    *max = *a;
    if (*b < *min) *min = *b;
    if (*c < *min) *min = *c;
    if (*b > *max) *max = *b;
    if (*c > *max) *max = *c;
}

int main() {
    int x = 5, y = 10, z = 15, result;
    int evenCount, oddCount;
    int minVal, maxVal;

    // Використання copyValue
    cout << "Перед копіюванням: y = " << y << endl;
    copyValue(&x, &y);
    cout << "Після копіювання: y = " << y << endl;

    // Використання countEvenOdd
    countEvenOdd(&x, &y, &z, &evenCount, &oddCount);
    cout << "Парних чисел: " << evenCount << ", непарних чисел: " << oddCount << endl;

    // Використання multiply
    multiply(&x, &y, &result);
    cout << "Результат множення x і y: " << result << endl;

    // Використання swapWithoutTemp
    cout << "Перед swapWithoutTemp: x = " << x << ", y = " << y << endl;
    swapWithoutTemp(&x, &y);
    cout << "Після swapWithoutTemp: x = " << x << ", y = " << y << endl;

    // Використання findMinMax
    findMinMax(&x, &y, &z, &minVal, &maxVal);
    cout << "Мінімальне значення: " << minVal << ", максимальне значення: " << maxVal << endl;

    return 0;
}

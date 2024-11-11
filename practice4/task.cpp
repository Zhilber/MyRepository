#include <iostream>
using namespace std;

// �������, �� ����� �������� � ���� ����� � ����
void copyValue(int* source, int* destination) {
    *destination = *source;
}

// �������, �� ���� ���� �� ������ �����
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

// �������, �� ������� ��� ����� � ������ ��������� ����� ��������
void multiply(int* a, int* b, int* result) {
    *result = (*a) * (*b);
}

// �������, �� ����� �������� ���� ������ ������ ��� ������������ ��������� �����
void swapWithoutTemp(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// �������, �� ��������� �������� � ����������� �������� � ����� �����
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

    // ������������ copyValue
    cout << "����� ����������: y = " << y << endl;
    copyValue(&x, &y);
    cout << "ϳ��� ���������: y = " << y << endl;

    // ������������ countEvenOdd
    countEvenOdd(&x, &y, &z, &evenCount, &oddCount);
    cout << "������ �����: " << evenCount << ", �������� �����: " << oddCount << endl;

    // ������������ multiply
    multiply(&x, &y, &result);
    cout << "��������� �������� x � y: " << result << endl;

    // ������������ swapWithoutTemp
    cout << "����� swapWithoutTemp: x = " << x << ", y = " << y << endl;
    swapWithoutTemp(&x, &y);
    cout << "ϳ��� swapWithoutTemp: x = " << x << ", y = " << y << endl;

    // ������������ findMinMax
    findMinMax(&x, &y, &z, &minVal, &maxVal);
    cout << "̳������� ��������: " << minVal << ", ����������� ��������: " << maxVal << endl;

    return 0;
}

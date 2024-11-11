#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void runAllFunctions() {
    cout << "Sum of ints: " << sum(3, 5) << "\n";
    cout << "Sum of doubles: " << sum(3.5, 2.1) << "\n";
    cout << "Sum of strings: " << sum(string("Hello, "), string("World!")) << "\n";

    int x = 5, y = 10;
    int minValueByValue = min(x, y);
    int minValueByReference = min(x, y);
    cout << "Min by value: " << minValueByValue << "\n";
    cout << "Min by reference: " << minValueByReference << "\n";

    cout << "Area of square: " << area(4) << "\n";
    cout << "Area of rectangle: " << area(4, 6) << "\n";
    cout << "Area of circle: " << area(3.0) << "\n";
    cout << "Area of triangle: " << area(3.0, 4.0, 5.0) << "\n";

    int a = 10, b = 20;
    cout << "Before swap by reference: a = " << a << ", b = " << b << "\n";
    swap(a, b);
    cout << "After swap by reference: a = " << a << ", b = " << b << "\n";
    swap(a, b);
    cout << "After swap by value (only inside function): a = " << a << ", b = " << b << "\n";

    int n = 5, result;
    factorial(n, result);
    cout << "Factorial of " << n << " is " << result << "\n";

    cout << "Square of stars:\n";
    drawSquare(5);
}

int main() {
    runAllFunctions();
    return 0;
}

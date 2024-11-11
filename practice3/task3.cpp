#include <iostream>
#include <cmath>
using namespace std;

int area(int side) {
    return side * side;
}

int area(int length, int width) {
    return length * width;
}

double area(double radius) {
    return M_PI * radius * radius;
}

double area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

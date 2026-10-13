// Lab_05_1.cpp
// Новосад Захарій
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз
// Варіант 16

#include <iostream>
#include <cmath>

using namespace std;

// Прототип допоміжної функції
double h(const double a, const double b);

#ifndef UNIT_TEST
int main()
{
    double s, t;

    cout << "s = "; cin >> s;
    cout << "t = "; cin >> t;

    double c = (h(s * s, 1 + t) + h(1, s * t)) / (1 + pow(h(s, t), 2));

    cout << "c = " << c << endl;

    return 0;
}
#endif

// Визначення допоміжної функції
double h(const double a, const double b)
{
    return (a + b + a * a * b * b) / (a * a + b * b);
}


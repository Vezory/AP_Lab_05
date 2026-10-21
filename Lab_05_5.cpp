// Lab_05_5.cpp
// Новосад Захарій
// Лабораторна робота № 5.5
// Рекурсивні функції. Арифметична прогресія.
// Варіант 16

#include <iostream>
#include <iomanip>

using namespace std;

// Прототипи рекурсивних функцій згідно зі схемою методички (стор. 12)
double a_n(const double a1, const double d, const int n, int level, int &depth);
double sum_n(const double a1, const double d, const int n, int level, int &depth);

#ifndef UNIT_TEST
int main()
{
    double a1, d;
    int n;

    cout << "a1 = "; cin >> a1;
    cout << "d  = "; cin >> d;
    cout << "n  = "; cin >> n;

    if (n < 1)
    {
        cout << "n must be >= 1" << endl;
        return 1;
    }

    int depth_a = 0;
    cout << "\n--- Recursion traces for a_n() ---" << endl;
    double an_val = a_n(a1, d, n, 1, depth_a);

    int depth_s = 0;
    cout << "\n--- Recursion traces for sum_n() ---" << endl;
    double sn_val = sum_n(a1, d, n, 1, depth_s);

    cout << fixed << setprecision(2);
    cout << "\n============== RESULTS ==============" << endl;
    cout << "a(" << n << ")   = " << an_val << endl;
    cout << "depth a = " << depth_a << endl;
    cout << "-------------------------------------" << endl;
    cout << "S(" << n << ")   = " << sn_val << endl;
    cout << "depth S = " << depth_s << endl;
    cout << "=====================================" << endl;

    // Контрольна перевірка за аналітичними формулами
    double an_check = a1 + (n - 1) * d;
    double sn_check = (a1 + an_check) * n / 2.0;
    cout << "Control a(" << n << ") = " << an_check << endl;
    cout << "Control S(" << n << ") = " << sn_check << endl;

    return 0;
}
#endif

// Рекурсивна функція для знаходження n-го члена прогресії
// Рекурентне співвідношення: a_n = a_{n-1} + d, база: a_1 = a1
double a_n(const double a1, const double d, const int n, int level, int &depth)
{
    if (level > depth)
        depth = level;

    cout << " [a_n] level = " << level << endl;

    if (n == 1)
        return a1;
    else
        return a_n(a1, d, n - 1, level + 1, depth) + d;
}

// Рекурсивна функція для знаходження суми перших n членів прогресії
// Рекурентне співвідношення: S_n = S_{n-1} + a_n, база: S_1 = a1
double sum_n(const double a1, const double d, const int n, int level, int &depth)
{
    if (level > depth)
        depth = level;

    cout << " [sum_n] level = " << level << endl;

    if (n == 1)
        return a1;
    else
        return sum_n(a1, d, n - 1, level + 1, depth) + (a1 + (n - 1) * d);
}


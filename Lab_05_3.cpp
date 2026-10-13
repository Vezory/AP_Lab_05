// Lab_05_3.cpp
// Новосад Захарій
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 16

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип допоміжної функції
double s(const double x);

#ifndef UNIT_TEST
int main()
{
    double tp, tk, dt;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n  = "; cin >> n;

    dt = (tk - tp) / n;

    cout << fixed;
    cout << "-------------------------------" << endl;
    cout << "|" << setw(7) << "t" << "   |"
         << setw(13) << "z" << "   |"
         << endl;
    cout << "-------------------------------" << endl;

    double t = tp;
    while (t <= tk + dt / 2.0)
    {
        double z = s(t * t + 1.0) + 2.0 * pow(s(1.0 - t), 2) + s(1.0);

        cout << "|" << setw(7) << setprecision(2) << t << "   |"
             << setw(13) << setprecision(5) << z << "   |"
             << endl;

        t += dt;
    }
    cout << "-------------------------------" << endl;

    return 0;
}
#endif

// Визначення допоміжної функції
double s(const double x)
{
    if (abs(x) > 1.0)
    {
        return (cos(x) * cos(x) + 1.0) / exp(x);
    }
    else
    {
        double S = 0.0;
        double a = x;
        S = a;
        for (int k = 1; k <= 4; k++)
        {
            double R = (x * x) / (2.0 * k * (2.0 * k + 1.0));
            a *= R;
            S += a;
        }
        return S;
    }
}


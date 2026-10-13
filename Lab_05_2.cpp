// Lab_05_2.cpp
// Новосад Захарій
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 16 (функція ln(x) на основі ЛР 4.7)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи допоміжних функцій (1-й спосіб: void-функції з параметрами-посиланнями)
void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << "   |"
         << setw(10) << "ln(x)" << "   |"
         << setw(10) << "S" << "   |"
         << setw(5) << "n" << "   |"
         << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
             << setw(10) << setprecision(5) << log(x) << "   |"
             << setw(10) << setprecision(5) << s << "   |"
             << setw(5) << n << "   |"
             << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}
#endif

// Функція накопичення суми ряду Тейлора
void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 2.0 * (x - 1.0) / (x + 1.0);
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

// Функція перерахунку чергового доданку за рекурентною формулою
void A(const double x, const int n, double &a)
{
    double R = (((x - 1.0) / (x + 1.0)) * ((x - 1.0) / (x + 1.0))) * (2.0 * n - 1.0) / (2.0 * n + 1.0);
    a *= R;
}

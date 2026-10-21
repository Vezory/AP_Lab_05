// Lab_05_4.cpp
// Новосад Захарій
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 16

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Прототипи п'яти функцій
double S0(const int K, const int N);
double S1(const int K, const int N, const int j);
double S2(const int K, const int N, const int j);
double S3(const int K, const int N, const int j, double t);
double S4(const int K, const int N, const int j, double t);

#ifndef UNIT_TEST
int main()
{
    int K = 2;
    int N;

    cout << "N = "; cin >> N;

    if (N < K)
    {
        cout << "N must be >= 2" << endl;
        return 1;
    }

    cout << fixed << setprecision(6);
    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 0.0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 0.0) << endl;

    return 0;
}
#endif

// 1) Ітераційний спосіб (для контролю правильності)
double S0(const int K, const int N)
{
    double s = 0.0;
    for (int j = K; j <= N; j++)
        s += 1.0 * j * (N - j) / (1.0 * j * j + 1.0 * (N - j) * (N - j));
    return s;
}

// 2) Обчислення на рекурсивному підйомі, параметр зростає (j++)
double S1(const int K, const int N, const int j)
{
    if (j > N)
        return 0.0;
    else
        return (1.0 * j * (N - j) / (1.0 * j * j + 1.0 * (N - j) * (N - j))) + S1(K, N, j + 1);
}

// 3) Обчислення на рекурсивному підйомі, параметр спадає (j--)
double S2(const int K, const int N, const int j)
{
    if (j < K)
        return 0.0;
    else
        return (1.0 * j * (N - j) / (1.0 * j * j + 1.0 * (N - j) * (N - j))) + S2(K, N, j - 1);
}

// 4) Обчислення на рекурсивному спуску, параметр зростає (j++)
double S3(const int K, const int N, const int j, double t)
{
    t = t + (1.0 * j * (N - j) / (1.0 * j * j + 1.0 * (N - j) * (N - j)));
    if (j >= N)
        return t;
    else
        return S3(K, N, j + 1, t);
}

// 5) Обчислення на рекурсивному спуску, параметр спадає (j--)
double S4(const int K, const int N, const int j, double t)
{
    t = t + (1.0 * j * (N - j) / (1.0 * j * j + 1.0 * (N - j) * (N - j)));
    if (j <= K)
        return t;
    else
        return S4(K, N, j - 1, t);
}

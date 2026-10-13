// UnitTest_05_2.cpp
// Новосад Захарій
// Модульний тест для функції S(x, eps, n, s) до проекту Lab_05_2

#include "pch.h"
#include "CppUnitTest.h"

// Пряме посилання на основний проект без дублювання коду
#define UNIT_TEST
#include "../LAB05/Lab_05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
    TEST_CLASS(UnitTest052)
    {
    public:
        TEST_METHOD(TestMethod_S_1)
        {
            // Тест 1: x = 1.0, ln(1) = 0.0
            double s = 0;
            int n = 0;
            S(1.0, 1e-5, n, s);
            Assert::AreEqual(0.0, s, 1e-5);
        }

        TEST_METHOD(TestMethod_S_2)
        {
            // Тест 2: x = 2.0, ln(2) ≈ 0.693147
            double s = 0;
            int n = 0;
            S(2.0, 1e-5, n, s);
            Assert::AreEqual(std::log(2.0), s, 1e-4);
        }

        TEST_METHOD(TestMethod_S_3)
        {
            // Тест 3: x = 0.5, ln(0.5) ≈ -0.693147
            double s = 0;
            int n = 0;
            S(0.5, 1e-5, n, s);
            Assert::AreEqual(std::log(0.5), s, 1e-4);
        }
    };
}


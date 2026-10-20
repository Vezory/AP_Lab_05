// UnitTest_05_5.cpp
// Новосад Захарій
// Модульний тест для функцій a_n та sum_n до проекту Lab_05_5 (Варіант 16)

#include "pch.h"
#include "CppUnitTest.h"

// Пряме посилання на основний проект без дублювання коду
#define UNIT_TEST
#include "../LAB05/Lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest055
{
    TEST_CLASS(UnitTest055)
    {
    public:
        TEST_METHOD(TestMethod_BaseCase)
        {
            // Базовий випадок n = 1: a_1 = 5.0, d = 3.0 => a1 = 5.0, S1 = 5.0, depth = 1
            int depth_a = 0;
            double actual_a = a_n(5.0, 3.0, 1, 1, depth_a);
            Assert::AreEqual(5.0, actual_a, 1e-5);
            Assert::AreEqual(1, depth_a);

            int depth_s = 0;
            double actual_s = sum_n(5.0, 3.0, 1, 1, depth_s);
            Assert::AreEqual(5.0, actual_s, 1e-5);
            Assert::AreEqual(1, depth_s);
        }

        TEST_METHOD(TestMethod_An_Calculation)
        {
            // a1 = 2.0, d = 4.0, n = 5 => a5 = 2 + 4 * 4 = 18.0, depth = 5
            int depth = 0;
            double actual = a_n(2.0, 4.0, 5, 1, depth);
            Assert::AreEqual(18.0, actual, 1e-5);
            Assert::AreEqual(5, depth);
        }

        TEST_METHOD(TestMethod_Sum_Calculation)
        {
            // a1 = 2.0, d = 4.0, n = 5 => S5 = (2 + 18) / 2 * 5 = 50.0, depth = 5
            int depth = 0;
            double actual = sum_n(2.0, 4.0, 5, 1, depth);
            Assert::AreEqual(50.0, actual, 1e-5);
            Assert::AreEqual(5, depth);
        }

        TEST_METHOD(TestMethod_NegativeDiff)
        {
            // a1 = 10.0, d = -2.5, n = 4 => a4 = 10 - 7.5 = 2.5, S4 = 25.0, depth = 4
            int depth_a = 0;
            double actual_a = a_n(10.0, -2.5, 4, 1, depth_a);
            Assert::AreEqual(2.5, actual_a, 1e-5);
            Assert::AreEqual(4, depth_a);

            int depth_s = 0;
            double actual_s = sum_n(10.0, -2.5, 4, 1, depth_s);
            Assert::AreEqual(25.0, actual_s, 1e-5);
            Assert::AreEqual(4, depth_s);
        }
    };
}

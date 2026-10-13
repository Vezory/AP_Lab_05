// UnitTest_05_3.cpp
// Новосад Захарій
// Модульний тест для функції s(x) до проекту Lab_05_3

#include "pch.h"
#include "CppUnitTest.h"

// Пряме посилання на основний проект без дублювання коду
#define UNIT_TEST
#include "../LAB05/Lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest053
{
    TEST_CLASS(UnitTest053)
    {
    public:
        TEST_METHOD(TestMethod_s_zero)
        {
            // Тест 1: |x| <= 1, x = 0.0 => s(0) = 0.0
            double expected = 0.0;
            double actual = s(0.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }

        TEST_METHOD(TestMethod_s_one)
        {
            // Тест 2: |x| <= 1, x = 1.0 (сума ряду Тейлора для k = 0..4)
            double expected = 1.0 + 1.0 / 6.0 + 1.0 / 120.0 + 1.0 / 5040.0 + 1.0 / 362880.0;
            double actual = s(1.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }

        TEST_METHOD(TestMethod_s_greater_than_one)
        {
            // Тест 3: |x| > 1, x = 2.0 => (cos^2(2) + 1) / exp(2)
            double expected = (cos(2.0) * cos(2.0) + 1.0) / exp(2.0);
            double actual = s(2.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }
    };
}

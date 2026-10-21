// UnitTest_05_4.cpp
// Новосад Захарій
// Модульний тест для функцій S0-S4 до проекту Lab_05_4 (Варіант 16)

#include "pch.h"
#include "CppUnitTest.h"

// Пряме посилання на основний проект без дублювання коду
#define UNIT_TEST
#include "../LAB05/Lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest054
{
    TEST_CLASS(UnitTest054)
    {
    public:
        TEST_METHOD(TestMethod_N2_Zero)
        {
            // Для N = 2: j = 2..2 => 2 * (2 - 2) / (4 + 0) = 0.0
            double expected = 0.0;
            Assert::AreEqual(expected, S0(2, 2), 1e-5);
            Assert::AreEqual(expected, S1(2, 2, 2), 1e-5);
            Assert::AreEqual(expected, S2(2, 2, 2), 1e-5);
            Assert::AreEqual(expected, S3(2, 2, 2, 0.0), 1e-5);
            Assert::AreEqual(expected, S4(2, 2, 2, 0.0), 1e-5);
        }

        TEST_METHOD(TestMethod_N3_Analytical)
        {
            // Для N = 3:
            // j = 2: 2 * (3 - 2) / (4 + 1) = 2 / 5 = 0.4
            // j = 3: 3 * (3 - 3) / (9 + 0) = 0.0
            // Сума = 0.4
            double expected = 0.4;
            Assert::AreEqual(expected, S0(2, 3), 1e-5);
            Assert::AreEqual(expected, S1(2, 3, 2), 1e-5);
            Assert::AreEqual(expected, S2(2, 3, 3), 1e-5);
            Assert::AreEqual(expected, S3(2, 3, 2, 0.0), 1e-5);
            Assert::AreEqual(expected, S4(2, 3, 3, 0.0), 1e-5);
        }

        TEST_METHOD(TestMethod_N5_AllEqual)
        {
            // Для N = 5: перевірка збігу результатів усіх 5 способів
            double s0 = S0(2, 5);
            double s1 = S1(2, 5, 2);
            double s2 = S2(2, 5, 5);
            double s3 = S3(2, 5, 2, 0.0);
            double s4 = S4(2, 5, 5, 0.0);

            Assert::AreEqual(s0, s1, 1e-5);
            Assert::AreEqual(s0, s2, 1e-5);
            Assert::AreEqual(s0, s3, 1e-5);
            Assert::AreEqual(s0, s4, 1e-5);
        }
    };
}

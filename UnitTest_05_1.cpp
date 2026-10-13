// UnitTest_05_1.cpp
// Новосад Захарій
// Модульний тест для функції h(a, b) до проекту Lab_05_1

#include "pch.h"
#include "CppUnitTest.h"

// Підключення вихідного файлу основного проекту за відносним шляхом
// (пряме посилання на основний проект БЕЗ копіювання / дублювання тіла функції)
#define UNIT_TEST
#include "../Lab_05_1/Lab_05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest051
{
    TEST_CLASS(UnitTest051)
    {
    public:
        TEST_METHOD(TestMethod_h_1)
        {
            // Тест 1: a = 1.0, b = 1.0 => (1 + 1 + 1*1) / (1 + 1) = 3 / 2 = 1.5
            double expected = 1.5;
            double actual = h(1.0, 1.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }

        TEST_METHOD(TestMethod_h_2)
        {
            // Тест 2: a = 2.0, b = 1.0 => (2 + 1 + 4*1) / (4 + 1) = 7 / 5 = 1.4
            double expected = 1.4;
            double actual = h(2.0, 1.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }

        TEST_METHOD(TestMethod_h_3)
        {
            // Тест 3: a = 0.0, b = 2.0 => (0 + 2 + 0) / (0 + 4) = 2 / 4 = 0.5
            double expected = 0.5;
            double actual = h(0.0, 2.0);
            Assert::AreEqual(expected, actual, 1e-5);
        }
    };
}


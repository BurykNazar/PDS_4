#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab4_2\Source.cpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestNextCombination)
        {
            vector<int> perms = { 1, 2, 3 };
            int N = 5;
            int R = 3;

            bool result = nextCombination(perms, R, N);

            Assert::IsTrue(result);
            Assert::AreEqual(perms[0], 1);
            Assert::AreEqual(perms[1], 2);
            Assert::AreEqual(perms[2], 4);
        }

        TEST_METHOD(TestFind)
        {
            ui N = 6;
            ui R = 4;
          
            std::ostringstream oss;
            std::streambuf* orig_buf = std::cout.rdbuf(oss.rdbuf());

            find(N, R);
          
            std::string output = oss.str();
            Assert::IsTrue(output.find("{1, 2, 3, 4}") != std::string::npos);
            Assert::IsTrue(output.find("{1, 2, 3, 5}") != std::string::npos);
            Assert::IsTrue(output.find("{1, 2, 4, 5}") != std::string::npos);
            Assert::IsTrue(output.find("{2, 3, 4, 5}") != std::string::npos);
    
            std::cout.rdbuf(orig_buf);
        }

        TEST_METHOD(TestGetFactorial)
        {
            Assert::AreEqual(getFactorial(0), 1ull);
            Assert::AreEqual(getFactorial(1), 1ull);
            Assert::AreEqual(getFactorial(2), 2ull);
            Assert::AreEqual(getFactorial(3), 6ull);
            Assert::AreEqual(getFactorial(4), 24ull);
            Assert::AreEqual(getFactorial(5), 120ull);
        }
    };
}

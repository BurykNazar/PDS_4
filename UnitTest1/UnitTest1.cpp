#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab4_1\Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ui N = 5;
			vector<vector<int>> perms = findPermutations(N);
			Assert::AreEqual(perms.size(), (size_t)120);
			Assert::AreEqual(perms[0][0], 1);
			Assert::AreEqual(perms[1][0], 1);
			Assert::AreEqual(perms[1][1], 2);
		}

		TEST_METHOD(TestMethod2)
		{
			ui N = 3;
			vector<vector<int>> perms = findPermutations(N);
			Assert::AreEqual(perms.size(), (size_t)6);
			Assert::AreEqual(perms[0][0], 1);
			Assert::AreEqual(perms[0][1], 2);
			Assert::AreEqual(perms[0][2], 3);
		}

		TEST_METHOD(TestMethod3)
		{
			ui N = 4;
			vector<vector<int>> perms = findPermutations(N);
			Assert::AreEqual(perms.size(), (size_t)24);
			Assert::AreEqual(perms[0][0], 1);
			Assert::AreEqual(perms[0][1], 2);
			Assert::AreEqual(perms[3][0], 1);
			Assert::AreEqual(perms[3][1], 3);
		}
	};
}

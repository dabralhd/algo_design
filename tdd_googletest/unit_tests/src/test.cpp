#include "math_functions.h"
#include "binary_search.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(TestSuiteMath, Factorial_TEST) {
	ASSERT_TRUE(fact(0)==1);
}

TEST(TestSuite_Binary_Search, T1) {
	vector<int> nums {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ASSERT_EQ(binary_search(nums, 0), 0);
	ASSERT_EQ(binary_search(nums, 1), 1);
	ASSERT_EQ(binary_search(nums, 5), 5);
	ASSERT_EQ(binary_search(nums, 2), 2);
	ASSERT_EQ(binary_search(nums, 8), 8);
	ASSERT_EQ(binary_search(nums, 9), 9);

}

TEST(TestSuite_Binary_Search, T2) {
	vector<int> nums {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ASSERT_EQ(binary_search(nums, 10), -1);
	ASSERT_EQ(binary_search(nums, 11), -1);
	ASSERT_EQ(binary_search(nums, 15), -1);
	ASSERT_EQ(binary_search(nums, 12), -1);
	ASSERT_EQ(binary_search(nums, 18), -1);
	ASSERT_EQ(binary_search(nums, 19), -1);

}


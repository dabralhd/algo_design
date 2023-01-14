#include "math_functions.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(TestSuiteMath, Factorial_TEST) {
	ASSERT_TRUE(fact(0)==1);
}

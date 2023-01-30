#include "leetcode_medium.h"

// function declarations
void test_threeSum_all_pairs(std::vector<int> v);
void test_threeSum_all_pairs_1();
void test_threeSum_all_pairs_2();

int main() {
  // test_threeSum_all_pairs_1();
  test_threeSum_all_pairs_2();
  return 0;
}

void test_threeSum_all_pairs_2() {
  int arr[] = {-1, 0, 1, 2, -1, -4};

  std::vector<int> vec;
  vec.assign(arr, arr + sizeof(arr) / sizeof(int));
  test_threeSum_all_pairs(vec);
}

void test_threeSum_all_pairs_1() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, -1};

  std::vector<int> vec;
  vec.assign(arr, arr + sizeof(arr) / sizeof(int));
  test_threeSum_all_pairs(vec);
}

void test_threeSum_all_pairs(std::vector<int> v) {
  Solution s;

  auto result = s.threeSum(v);
  for (int i = 0; i < result.size(); ++i) {
    auto v = result[i];
    std::cout << i << "th answer: " << std::endl;
    for (int j = 0; j < v.size(); ++j) {
      std::cout << "\t" << j << "th idx: " << v[j] << std::endl;
    }
  }
}

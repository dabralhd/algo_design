
#ifndef __LEETCODE_MEDIUM__
#define __LEETCODE_MEDIUM__

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  // https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::multimap<int, int> myMap;

    for (auto idx = 0; idx < nums.size(); ++idx) {
      myMap.insert(std::pair<int, int>(nums[idx], idx));
      auto other = myMap.find(target - nums[idx]);
      if ((other != myMap.end()) && (other->second != idx)) {
        return std::vector<int>({idx, other->second});
      }
    }

    return std::vector<int>(2, -1);
  }

  std::vector<std::vector<int>> twoSum_all_pairs(std::vector<int> &nums,
                                                 int target) {
    std::multimap<int, int> myMap;
    std::vector<std::vector<int>> ret;

    for (int i = 0; i < nums.size(); ++i) {
      int other = target - nums[i];
      std::multimap<int, int>::iterator itr = myMap.find(other);
      if (itr != myMap.end()) {
        std::vector<int> sample(2);
        sample[0] = itr->second;
        sample[1] = i;
        ret.push_back(sample);
      }
      myMap.insert(std::pair<int, int>(nums[i], i));
    }

    return ret;
  }

  // https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    const int target = 0;
    std::unordered_map<int, bool> myMap;

    for (int i = 0; i < nums.size(); ++i) {
      int required = target - nums[i];
      std::vector<int> num_i(nums.size() - 1);
      copy(nums.begin(), nums.begin() + i,
           num_i.begin());  // copy first i elements
      if (i < nums.size())
        copy(nums.begin() + i + 1, nums.end(), num_i.begin() + i + 1);

      auto two = twoSum_all_pairs(
          num_i, required);  // typeof(two) is vector<vector<int>>

      for (int x = 0; x < two.size(); ++x) {
        auto it = find(two[x].begin(), two[x].end(), i);

        if (it == two[x].end()) {
          std::vector<int> three;
          three.push_back(i);
          three.push_back(two[x][0]);
          three.push_back(two[x][1]);
          std::sort(three.begin(), three.end());
          int key =
              100 * three[2] + 10 * three[1] +
              1 * three[0];  // note that all elements of three are always +ve
          std::cout << "key: " << key << std::endl;

          if (myMap.find(key) == myMap.end()) {
            std::cout << "unique key" << std::endl;
            myMap[key] = true;
            ret.push_back(three);
          }
        }
      }
    }
    return ret;
  }
};

#endif  //__LEETCODE_MEDIUM__
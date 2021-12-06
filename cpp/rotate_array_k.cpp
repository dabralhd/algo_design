// rotate an array

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (k != 0) {
            std::vector<int> vec(k);

            std::copy(nums.begin()+nums.size()-k, nums.end(), vec.begin());

            for(int idx=nums.size()-1-k; idx>=0; idx--) {
                nums[idx+k] = nums[idx];
            }
            
            std::copy(vec.begin(), vec.end(), nums.begin());            
        }
    }
};

int main() {
    std::vector<int> nums {0,1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums, 2);

    for(auto x:nums) 
        std::cout << x << " " << std::endl;
}
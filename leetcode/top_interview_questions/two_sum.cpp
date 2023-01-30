#include "solution.h"

class Solution {
public:

    /*
     * perform binary search for target in a array. return its index if found, else return -1.
     * nums: an array of sorted integers
     * left: left index
     * right: right index
     * target: the number to find
    */
    int bst_search_c_style(const int nums[], const int left, const int right, int target) {
        std::cout << "array size: " << right - left << std::endl;

        if ( left < right) {
            int middle = left + (right-left)/2;
            if (target == nums[middle]) 
                return middle;
            else if(target < nums[middle])
                return bst_search_c_style(nums, left, middle-1, target);
            else
                return bst_search_c_style(nums, middle+1, right, target);
        }

        return -1;
    }

    /*
     * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. 
     https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
     */
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        return ret;
        
    }


    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/        
        std::multimap<int, int> myMap;
        
        for (auto idx=0; idx < nums.size(); ++idx) {
            myMap.insert(std::pair<int, int>(nums[idx], idx));
            auto other = myMap.find(target - nums[idx]);
            if ((other != myMap.end()) && (other->second != idx)) {
                return std::vector<int>({idx, other->second});
            }
        }

        return std::vector<int>(2, -1);               
    }


        
};

// function declarations
void test_bin_search_1();
void test_bin_search_2();
void test_twoSum_1();
void test_twoSum_2();
void test_twoSum_3();
void test_twoSum_all_pairs(std::vector<int> v, int target);

int main() {
    //test_bin_search_1();
    //test_bin_search_2();
    test_twoSum_3();
    
}

void test_twoSum_3() {
    Solution s;
    int arr[] =  {3,2,4};
    std::vector<int> vec;
    vec.assign (arr, arr + sizeof(arr)/sizeof(int));
    
    std::vector<int> result = s.twoSum(vec, 6);

    for(int i=0; i<result.size(); ++i) {
        std::cout << i << "th idx: " << result[i] << std::endl;
    }

    if (( result[0] == 1) && (result[1] == 2))
        std::cout << "pass" << std::endl;
    else if (( result[0] == 2) && (result[1] == 1))
        std::cout << "pass" << std::endl;        
    else 
        std::cout << "fail" << std::endl; 
}

void test_twoSum_2() {
    Solution s;
    int arr[] =  {1, 4, 7, 8, 9, 10,20};
    std::vector<int> vec;
    vec.assign (arr, arr + sizeof(arr)/sizeof(int));
    
    std::vector<int> result = s.twoSum(vec, 11);

    for(int i=0; i<result.size(); ++i) {
        std::cout << i << "th idx: " << result[1] << std::endl;
    }


    if (( result[0] == 0) && (result[1] == 5))
        std::cout << "pass" << std::endl;
    else 
        std::cout << "fail" << std::endl; 
}

void test_twoSum_1() {
    Solution s;
    int arr[] =  {1, 4, 7, 8, 9, 10,20};
    std::vector<int> vec;
    vec.assign (arr, arr + sizeof(arr)/sizeof(int));
    
    std::vector<int> result = s.twoSum(vec, 4);
    std::cout << "0th idx: " << result[0] << std::endl;
    std::cout << "1st idx: " << result[1] << std::endl;

    if (( result[0] == -1) && (result[1] == -1))
        std::cout << "pass" << std::endl;
    else 
        std::cout << "fail" << std::endl; 
}

void test_bin_search_1() {
    Solution s;
    int arr[] =  {1, 4, 7, 8, 9, 10,20};
    if ( s.bst_search_c_style(arr, 0, sizeof(arr)/sizeof(int), 4) == 1)
        std::cout << "pass" << std::endl;
    else 
        std::cout << "fail" << std::endl; 
}

void test_bin_search_2() {
    Solution s;
    int arr[] =  {1, 4, 7, 8, 9, 10,20};
    if ( s.bst_search_c_style(arr, 0, sizeof(arr)/sizeof(int), -4) == -1)
        std::cout << "pass" << std::endl;
    else 
        std::cout << "fail" << std::endl; 
}
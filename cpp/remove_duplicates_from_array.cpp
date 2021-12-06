// Remove Duplicates from Sorted Array
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int first = 0;
        
        first = 0;
        for (int second=1; second<nums.size(); ++second) {
            
            if(nums[second] == nums[second - 1])
                continue;
            else {
                nums[++first] = nums[second];                
            }     
        }
        
        return first + 1;
        
    }
};
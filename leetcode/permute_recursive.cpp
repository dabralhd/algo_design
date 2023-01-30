class Solution {
    vector<vector<int>> perms ;
    void permute(vector<int>& nums, int pos) {
        if(pos == nums.size()-1) {
            perms.push_back(nums);        
            return;
        }

        for(int i=pos; i<nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permute(nums, pos+1);
            swap(nums[i], nums[pos]);
        }        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0);       
        return perms;
    }
};

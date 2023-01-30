// https://leetcode.com/problems/permutations/

class Solution {
    vector<int> remove_element(int mask, const vector<int>& nums) {
        vector<int> ret;
        for(int i=0; i<nums.size(); i++) {
            if(i != mask) {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vv;
        if(nums.size()==1) {
            vv.push_back(nums);
            return vv;
        }

        for(int i=0; i<nums.size(); i++) {
            vector<int> v1 = remove_element(i, nums);
            auto vv1 = permute(v1);
            for( auto &x : vv1)
                x.emplace_back(nums[i]);
            for(auto y : vv1)
                vv.emplace_back(y);
        }
        return vv;
            
        
    }
};

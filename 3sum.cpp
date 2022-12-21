/*
c++ solution to 3sum problem mentioned at 
https://leetcode.com/problems/3sum/description/

There are some key concepts:
  1. Hash function for vector<int> is not defined in STL, so you must define it using a structure. It is to be noted that the overload of operator()
  must use 2 consts, one for the argument and other for saying that this function does not change the structure
  2. pass vector<int> by reference to operator()
*/
struct vector_hash {
    // key concept here
    size_t operator()(const vector<int> &vec) const  {
        size_t ret = 0;
        for(auto x : vec) {
            ret += hash<int>()(x);
        }            
        return ret;
    }
};

class Solution {public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<vector<int>, vector_hash> ret;
        for(int i=0; i<nums.size(); i++) {            
            unordered_set<int> s2;
            for(int j=0; j<nums.size(); j++) {
                if(j!=i) {
                    // find a number such that nums[j] + nums[i] = -key                    
                    auto itr = s2.find(-nums[i]-nums[j]);
                    if(itr!=s2.end()) {
                        vector<int> triplet {nums[i], nums[j], *itr};
                        sort(triplet.begin(), triplet.end());
                        ret.insert(triplet);
                    }
                    s2.insert(nums[j]);
                }                                                            
            }
        }
        vector<vector<int>> vec;
        for(auto elem : ret) 
            vec.push_back(elem);
        return vec;
    } 
};

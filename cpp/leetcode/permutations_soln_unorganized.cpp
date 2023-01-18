// https://leetcode.com/problems/permutations/

struct Vec_Equal {
    public:
        bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a.size() != b.size())
            return false;

        for(int i=0; i<a.size(); i++) {
            if (a[i] == b[i])  
                continue;
            else
                return false;
        }
        
        return true;
    }

};

struct Vec_Hasher {
    public:
    size_t operator()(const vector<int>& vi) {

        size_t h = 0;
        for(auto i : vi) {
            h ^= hash<int>()(i);
        }
        return h;

    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<vector<int>, Vec_Hasher, Vec_Equal> s;
        vector<vector<int>> ret;
        if(!nums.size()) return ret;
        vector<int> seed;
        seed.push_back(nums[0]);
        s.insert(seed);
        for(int i=1; i<nums.size(); i++) {
            unordered_set<vector<int>, Vec_Hasher, Vec_Equal> s2;
            for(auto sub : s) {  // for every sub-array in s
                for(auto itr=sub.begin(); itr!=sub.end(); itr++) {
                    sub.insert(itr, nums[i]);
                    s2.insert(sub);
                }
                s = s2;                
            }
        }

        for(auto sub : s)
            ret.push_back(sub);           
        
        return ret;   
    }
};

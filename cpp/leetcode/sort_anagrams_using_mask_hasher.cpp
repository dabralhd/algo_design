struct mask_hasher {
    size_t operator()(const array<int, 26>& mask) const {
        size_t code = 0;
        for(auto x : mask) {
            code <<= 1;
            code += hash<int>()(x);
        }
        return code;
    }

};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // represent string using 26 integer array
        unordered_map<array<int, 26>, vector<string>, mask_hasher> m;
        for(auto str : strs) {
            array<int, 26> mask {};
            for(auto ch : str) {
                mask[ch-'a'] += 1;
            }
            m[mask].push_back(str);
        }

        vector<vector<string>> vvs;
        for(auto p : m) {
            vvs.push_back(p.second);
        }
        return vvs;        
    }
};

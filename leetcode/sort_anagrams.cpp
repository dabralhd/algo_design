class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> vvs;

        for(auto str : strs) {
            auto temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }

        for(auto pair : m) {
            vvs.push_back(pair.second);
        }

        return vvs;       
    }
};

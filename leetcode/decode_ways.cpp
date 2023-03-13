// https://leetcode.com/problems/decode-ways/description/

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int numCodingAt(int pos, string s, vector<int>& dp) {
        bool branches =  false;

        int res = 0;
        int i1 = 0;
        if(dp[pos]!=-1)
            return dp[pos];            
        else if(pos < s.size()) {
            i1 = atoi(s.substr(pos, 1).c_str());                                             
            if(i1>=1 && i1<=9) {
                res = numCodingAt(pos+1, s, dp);   

            }
            if(pos+1<s.size()) {
                int i2 = 0;
                i2 = atoi(s.substr(pos, 2).c_str());  
                if(i2>=10 && i2<=26)
                    res += numCodingAt(pos+2, s, dp);
            } 
            dp[pos] = res;            
        }

        return res;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        dp[s.size()] = 1;
        return numCodingAt(0, s, dp);
    }
};

int main() {
    /*
    1 -> A
    2-> B
    3-> C
    ,
    ,
    ,
    26 -> Z
    */
    string s = "12";  // ABC, 123 = LC, 123 = AW
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;

    s = "123";  // ABC, 123 = LC, 123 = AW
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;

    s = "0123";
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;    

    s = "1236";
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;    

    s = "10";
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;    

    s = "9725311523";
    cout << "for string: " << s << ", " << Solution().numDecodings(s) << " ways of decode are possible" << endl;    

    return 0;
}
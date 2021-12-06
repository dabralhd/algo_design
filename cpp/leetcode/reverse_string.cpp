#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<char>& s, int first, int last) {
        for(int i=first; i<last/2; ++i) {
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }

    }

    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }
};

int test(vector<char> s, string desc) {
    cout << desc << endl;
    cout << "input: " << string(s.begin(), s.end()) << endl;
    Solution sol;
    sol.reverseString(s);
    cout << "reversed: " << string(s.begin(), s.end()) << endl << endl;
    return 0;
}

int test1() {
    string str {"hello"};
    string desc {"test1"};
    vector<char> v_str(str.begin(), str.end());

    test(v_str, desc);
    return 0;
}

int test2() {
    string str {"abcd"};
    string desc {"test2"};
    vector<char> v_str(str.begin(), str.end());

    test(v_str, "test1");
    return 0;
}

int main()
{
    test1();
    test2();
    return 0;
}
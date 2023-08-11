#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto print_vi = [](vector<int> vi){for_each(vi.rbegin(), vi.rend(), [](int i){cout << i << " ";});};
        //print_vi(nums1);
        //print_vi(nums2);

        auto it1 = nums1.rbegin() + n;        
        auto it2 = nums2.rbegin();
        auto out = nums1.rbegin();

        while(it1!=nums1.rend() && it2!=nums2.rend()) {                      
            auto first = *it1;
            auto second = *it2;

            if(first > second) {
                *out = first;
                ++it1;
            } else {
                *out = second;                
                ++it2;
            }
            ++out;
        }

        while(it1!=nums1.rend()) {
            *out = *it1;
            out++; it1++; 
        }

        while(it2!=nums2.rend()) {
            *out = *it2;
            out++; it2++; 
        }        

    //return nums1;
    }
};

void test(vector<int> v1, vector<int> v2) {
    cout << "> test: " << endl;
    const int m = v1.size();
    const int n = v2.size();
    vector<int> v3(m + n);

    copy(v1.begin(), v1.end(), v3.begin());
    auto display = [](int x) {cout << x <<" "; };
    cout << "v1: ";
    for_each(v3.begin(), v3.end(), display);
    cout << endl;

    cout << "v2: ";
    for_each(v2.begin(), v2.begin()+n, display);
    cout << endl;    

    cout << "merging: " << endl;
    Solution().merge(v3, m, v2, n);

    cout << "v1: ";
    for_each(v3.begin(), v3.end(), display);
    cout << endl << endl;
}

int main() {
    test({1,2,3,4}, {1,5});

    test({1,2,3,4}, {1,1,1,1,1});

    test({1,2,3,4}, {});

    test({}, {});

    test({1,2,3}, {2,5,6});

    return 0;
}
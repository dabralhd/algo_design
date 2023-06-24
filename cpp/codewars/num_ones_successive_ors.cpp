#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_ones(vector<int>& nums) {
    int ret = 0;
    for(int i=0; i<nums.size()-1; i++) {
        int ones = count(nums.begin(), nums.end()-i, 1);        
        if(ones==nums.size()-i) {
            return ret + ones*(ones+1)/2;       
        }
        ret += ones;
        for(int j=0; j<nums.size()-i-1; j++)    
            nums[j] |= nums[j+1];
    }
    return ret+1;
}

void test(vector<int> nums) {
    cout << endl;
    for_each(nums.begin(), nums.end(), [](int i){cout << i << " ";});
    cout << endl << count_ones(nums);
}

int main() {
    test({1, 1, 1});
    test({1, 0, 1});
    test({1, 1, 1, 0, 0, 1, 0});

}
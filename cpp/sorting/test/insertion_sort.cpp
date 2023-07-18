#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sort(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++) {
        for(int j=i; j>0 && nums[j]<nums[j-1]; j--) {
            swap(nums[j], nums[j-1]);
        }
    }
}

void test_insertion_sort_helper(vector<int> nums) {
    cout << "given vector: {";
    for_each(nums.begin(), nums.end(), [](int x) { cout << x <<" ";});
    cout << "}" << endl;    

    insertion_sort(nums);

    cout << "after sorting: {";
    for_each(nums.begin(), nums.end(), [](int x) { cout << x <<" ";});
    cout << "}" << endl;    
}

void test_sort() {
    test_insertion_sort_helper({4, 6, 78, -1, 90, 0, 4, 7});
}

int main() {
    test_sort();
}
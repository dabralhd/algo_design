#include <vector>

using namespace std;

int binary_search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high) {
        auto mid = low + (high - low) / 2;
        if(target < nums[mid])
            high = mid - 1;
        else if(nums[mid] < target)
            low = mid + 1;
        else
            return mid;
    }
    return -1;        
}

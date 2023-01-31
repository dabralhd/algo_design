#include <iostream>
#include <vector>

using namespace std;

int get_pivot(vector<int> nums) {
	int l = 0;
	int h = nums.size() - 1;

	cout << "l: " << l << endl << "h: " << h << endl;

	while (l <= h) {
		auto mid = (l + h) / 2;

		if ((l == h) || (mid-1>=0 && mid+1<nums.size() && nums[mid]<=nums[mid+1] && nums[mid]<=nums[mid-1]))
			return mid;

		if (nums[mid] < nums[l])
			h = mid - 1;
		else 
			l = mid + 1;
	}

	return -1;

}


int main() {
    	vector<int> nums {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
        auto p = get_pivot(nums);
        cout << "pivot is: " << p << endl;

		nums = {7, 8, 9, 0};
        p = get_pivot(nums);
        cout << "pivot is: " << p << endl;

		nums = {7, 8, 9};
        p = get_pivot(nums);
        cout << "pivot is: " << p << endl;		

}
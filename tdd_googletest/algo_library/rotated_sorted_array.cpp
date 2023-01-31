/*
 * rotated_array.cpp
 *
 *  Created on: 20-Jan-2023
 *      Author: hem
 */
#include "rotated_sorted_array.h"
#include <iostream>

int get_pivot(vector<int> nums) {
	int l = 0;
	int h = nums.size() - 1;

	//cout << "l: " << l << endl << "h: " << h << endl;

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



/*
 * bin_search.cpp
 *
 *  Created on: 19-Jan-2023
 *      Author: hem
 */
#include "binary_search.h"

int binary_search(vector<int> nums, int target) {
	int low {0};
	int high {nums.size() - 1};

	while(low <= high) {
		auto mid = (low + high) / 2;

		if(target < nums[mid])
			high = mid - 1;
		else if (target > nums[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}




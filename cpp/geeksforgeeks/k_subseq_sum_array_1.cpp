// Method 1: Brute force, scan through the array maintaining the highest among
// previous K elements.

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int get_max_idx_subseq(const vector<int> nums, 
                        const int begin, 
                        const int end,
                        const int k, 
                        int idx_max = 0) {
  for (int i = begin; i < end; ++i) {
    if (nums[i] > nums[idx_max]) idx_max = i;
  }

  return idx_max;
}

int main() {
  vector<int> nums;
  vector<int> max_values;
  int number = 0;
  int k = 0;

  while (number >= 0) {
    cout << "Enter number: " << endl;
    cin >> number;
    if (number < 0) break;
    nums.push_back(number);
  }

  cout << endl << "{ ";
  for (const auto &x : nums) cout << x  << "  ";
  cout << "}" << endl;

  cout << "Enter k: " << endl;
  cin >> k;

  cout << "finding max k-subsequence value: " << endl;
  int max_idx = get_max_idx_subseq(nums, 0, k, k);
  max_values.push_back(nums[max_idx]);

  for (int i = 1; i < nums.size()-k+1; ++i) {
      if(max_idx == i) {
          max_idx = get_max_idx_subseq(nums, i, i+k, max_idx);
      } else if(nums[max_idx]<nums[i+k-1])  {
          max_idx = i+k-1;
      }
      max_values.push_back(nums[max_idx]);
  }

  cout << "showing output: " <<endl;
  cout << "{ ";
  for(auto x : max_values)
    cout << x << "  ";
  cout << "}" << endl;
}
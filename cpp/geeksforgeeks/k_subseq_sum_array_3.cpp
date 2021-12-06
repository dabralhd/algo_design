// Method 3: use a simple variable to store the highest element in the current
// window
#include <iostream>
#include <vector>

using namespace std;

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
  for (const auto &x : nums) cout << x << "  ";
  cout << "}" << endl;

  cout << "Enter k: " << endl;
  cin >> k;

  cout << "finding max k-subsequence value: " << endl;

  int max_in_window = 0;
  max_in_window = nums[0];
  
  for (int i = 1; i < k; ++i) {
    if (max_in_window < nums[i]) { 
      max_in_window = nums[i];
    }
  }

  max_values.push_back(max_in_window);

  for (int i = k; i < nums.size(); ++i) {
    if (max_in_window < nums[i]) { 
      max_in_window = nums[i];
    }
    max_values.push_back(max_in_window);
  }

  cout << "showing output: " << endl;
  cout << "{ ";
  for (auto x : max_values) cout << x << "  ";
  cout << "}" << endl;
}
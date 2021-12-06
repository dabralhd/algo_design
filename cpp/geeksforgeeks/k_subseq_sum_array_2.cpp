// Method 2: use a stack/queue/deque to store the highest element in the current
// window
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

#define USE_STACK 1
#define USE_DEQUE 2

#define CONTAINER_TO_USE USE_STACK

#if CONTAINER_TO_USE == USE_STACK
#include <stack>
typedef stack<int> t_container;
#endif

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

  t_container aux;
  aux.push(nums[0]);

  for (int i = 1; i < k; ++i) {
    if (aux.top() < nums[i]) { 
      aux.pop();
      aux.push(nums[i]);
    }
  }

  max_values.push_back(aux.top());

  for (int i = k; i < nums.size(); ++i) {
    if (aux.top() < nums[i]) { 
      aux.pop();
      aux.push(nums[i]);
    }
    max_values.push_back(aux.top());
  }

  cout << "showing output: " << endl;
  cout << "{ ";
  for (auto x : max_values) cout << x << "  ";
  cout << "}" << endl;
}
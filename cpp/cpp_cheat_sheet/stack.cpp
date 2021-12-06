#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> my_stack;
  int num = 1;

  cout << "Entering elements at the rear end: " << endl;
  while (num > 0) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_stack.push(num);
  }

  num = 1;
  cout << "removing element from front:" << endl;
  while (!my_stack.empty()) {
    cout << "Deleting element in front. Element to delete: " << my_stack.top()
         << endl;
    my_stack.pop();
  }
}

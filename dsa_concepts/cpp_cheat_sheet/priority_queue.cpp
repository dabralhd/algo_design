#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> mypq;
  int num = 1;

  cout << "Entering elements at the rear end: " << endl;
  while (num > 0) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    mypq.push(num);
  }

  num = 1;
  cout << "removing element from front:" << endl;
  while (!mypq.empty()) {
    cout << "Element at the top of the queue is: " << mypq.top()
         << endl;
    mypq.pop();
  }
}

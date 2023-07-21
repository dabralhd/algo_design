#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Comp {
  bool operator()(const int x, const int y) { return y<x; }

};

int main() {
  priority_queue<int> mypq;

  priority_queue<int, vector<int>, Comp> mypq2;  
  int num = 1;

  cout << "Entering elements at the rear end: " << endl;
  while (num > 0) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    mypq2.push(num);
  }

  num = 1;
  cout << "removing element from front:" << endl;
  while (!mypq2.empty()) {
    cout << "Element at the top of the queue is: " << mypq2.top()
         << endl;
    mypq2.pop();
  }
}

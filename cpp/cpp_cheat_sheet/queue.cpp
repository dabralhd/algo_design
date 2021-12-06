#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> my_queue;
  int num = 1;

  cout << "Entering elements at the rear end: " << endl;
  while (num > 0) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_queue.push(num);
  }

  num = 1;
  cout << "removing element from front:" << endl;
  while (!my_queue.empty()) {
    cout << "Deleting element in front. Element to delete: " << my_queue.front()
         << endl;
    my_queue.pop();
  }
}

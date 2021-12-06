#include <iostream>
#include <array>

using namespace std;

template <typename T>
void display_container(const T& my_container) {
  cout << "Displaying container: ";
  cout << "{ ";
  for (const auto& t : my_container) cout << t << "  ";
  cout << " }" << endl;
}

int main() {
  array<int, 10> my_array = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int num = 0;
  int index = 0;

  num = 1;
  cout << "Entering elements at given index: " << endl;
  while (index >= 0) {
    cout << "Enter index: ";
    cin >> index;
    if (index < 0) break;
    cout << "Enter number: ";
    cin >> num;

    my_array[index] = num;
  }

  display_container(my_array);


}

#include <iostream>
#include <list>

using namespace std;

template <typename T>
void display_container(const T& my_container) {
  cout << "Displaying container: ";
  cout << "{ ";
  for (const auto& t : my_container) cout << t << "  ";
  cout << " }" << endl;
}

int main() {
  list<int> my_list;
  int num = 1;

  cout << "Entering elements at the beginning: " << endl;
  while (num) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_list.insert(my_list.begin(), num);
  }

  display_container(my_list);

  num = 1;
  cout << "Entering elements at the end: " << endl;
  while (num) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_list.insert(my_list.end(), num);
  }

  display_container(my_list);

  num = 1;
  cout << "Delete element by iterator:" << endl;
  while (num) {
    cout << "Enter index to delete: ";
    cin >> num;
    if (num < 0) break;
    
    list<int>::iterator it = my_list.begin();
    advance(it, num);
    my_list.erase(it);
  }

  display_container(my_list);

}

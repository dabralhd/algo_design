#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display_container(const T& my_container) {
  cout << "Displaying container: ";
  cout << "{ ";
  for (const auto& t : my_container) cout << t << "  ";
  cout << " }" << endl;
}

int main() {
  vector<int> my_vector;

  vector<int> v2 = {1,2};

  int num = 1;

  cout << "Entering elements at the end (push_back): " << endl;
  while (num) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_vector.push_back(num);
  }

  display_container(my_vector);

  num = 1;
  cout << "Entering elements at the end (insert): " << endl;
  while (num) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_vector.insert(my_vector.end(), num);
  }

  display_container(my_vector);

  cout << "Entering elements at the beginning (insert): " << endl;
  while (num) {
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) break;

    my_vector.insert(my_vector.begin(), num);
  }

  display_container(my_vector);

  num = 1;
  cout << "Delete element by iterator:" << endl;
  while (num) {
    cout << "Enter index to delete: ";
    cin >> num;
    if (num < 0) break;
    
    //vector<int>::iterator it = my_vector.begin();
    //advance(it, num);
    my_vector.erase(my_vector.begin() + num);
  }

  display_container(my_vector);

}

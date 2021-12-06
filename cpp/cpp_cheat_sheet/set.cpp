#include <iostream>
#include <set>

using namespace std;

template <typename T>
void display_container(const T& my_container) {
  cout << "Displaying container. size: " << my_container.size() << endl;
  cout << "{ ";
  for (const auto& t : my_container) cout << t << "  ";
  cout << " }" << endl;
}

int main() {
    set<int> s1;
    int elem = 0;

    while (cin >> elem && elem>=0) {
        s1.insert(elem);
    }
    display_container(s1);

    cout << "enter element of elements to remove: " << endl;

    int idx = 0;
    while(cin>>idx && idx>=0) {
        s1.erase(idx);
    }
    display_container(s1);

    return 0;
}
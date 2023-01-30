// TODO: This code has bugs
#include <iostream>
#include <list>

using namespace std;

list<int> reverse_list(list<int>& L) {
    list<int> l1;
    for(const auto& node : L) {
        l1.push_back(L.front());
        L.pop_front();
    }
    return l1;
}

ostream& operator<<(ostream& os, const list<int>& l1) {
    for(int val : l1) {
        os << val << "->";
    }
    os << endl;
    return os;
}

int main() {
    list<int> l {1,2,3,4};
    cout << "demostrating how to invert a linked list" << endl;
    for(auto x : l)
        cout << x << "->";
    cout << endl;
    cout << l;
    cout << "after reversing list: " << endl;
    cout << reverse_list(l);
    cout << "original:" << endl;
    cout << l;

    return 0;
}

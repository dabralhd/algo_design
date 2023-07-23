#include "doubly_linked_list.hpp"
#include <vector>

using namespace std;

DoublyLinkedList create_list(const vector<uint32_t>& vi32) {
    DoublyLinkedList lst;
    for(auto i : vi32) {
        lst.push_front(i);
    }
    return lst;
}

int main() {
    auto lst = create_list({1, 78, 90, 100});    
    cout << "front: " << lst.front() << ", back: " << lst.back() << endl;
    while(lst.size()) {
        cout << lst.front() << endl;
        lst.pop_front();
    }
    return 0;
}
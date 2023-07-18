#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    unique_ptr<ListNode> next;
    ListNode(int v) : val {v}, next {nullptr} {}
    ~ListNode() {
        cout << "destructor called:" << endl;
    }
};

void insert_before(int val, unique_ptr<ListNode>& head) {
    unique_ptr<ListNode> temp = make_unique<ListNode>(val);
    temp->next = move(head);
    head = move(temp);
}

void delete_after(unique_ptr<ListNode>& head) {
    if (head && head->next) {
        head->next = move(head->next->next);
    }
}

void test_make_list_helper(vector<int> vi) {
    unique_ptr<ListNode> upl;
    for(auto x : vi)
        insert_before(x, upl);
    ListNode* ptr = upl.get();
    while(ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next.get();
    }
    cout << endl;
    
}

void test_make_list_1() {
    cout << "test 1" << endl;
    test_make_list_helper({1,2,3,4,5,6});

    cout << "test 2" << endl;
    test_make_list_helper({12, 78, 90});

}

int main() {
    test_make_list_1();
    return 0;
}

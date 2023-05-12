#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val, ListNode* ptr) : data { val }, next {ptr} {} 
    ListNode(int val) : ListNode(val, nullptr) {}
};

void push_front(int val, ListNode* &list) {
    ListNode* t = new ListNode(val, list);
    list = t;
}

// print a linked list
ostream& operator<<(ostream& os, ListNode* list) {
    while(list!=nullptr) {
        os << list->data << "->";
        list = list->next;
    }
    os << "->x";
    return os;
}

void test1() {
    ListNode* list;
    for(int i=1; i<=10; i++)
        push_front(i, list);
    cout << list;
    cout << list;

}

int main() {
    test1();
    return 0;
}
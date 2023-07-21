#include <iostream>
#include <memory>
#include "singly_linked_list.hpp"

using namespace std;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head {nullptr}, sz {0} {
    #ifdef DEBUG_MSG
        cout << "Constructed SinglyLinkedList: " << endl;
    #endif
} 

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    #ifdef DEBUG_MSG
        cout << "Destroyed SinglyLinkedList: " << endl;
    #endif
}

template <typename T>
void SinglyLinkedList<T>::insert_before(T& val) {
    if (head) {
        unique_ptr<ListNode> ptr = make_unique<ListNode>(val);
        ptr->set_next(move(head));
        head = move(ptr);
    } else {
        head = make_unique<ListNode>(val);
    }
    sz++;
}

// template <typename T>
// NodePtrType<T>& SinglyLinkedList<T>::find_node(const T& val ) {
//     auto  temp = head.get();
//     while(temp) {
//         if(temp->val==val)
//             return temp;
//     }
// }

template <typename T>
void SinglyLinkedList<T>::remove_after(const unique_ptr<ListNode>& ref) {
}

template <typename T>
void SinglyLinkedList<T>::traverse() {                
    auto ptr = head.get();
    while(ptr) {
        cout << ptr->get_val() << endl;
        ptr = ptr->get_next().get(); // illegal
    }
}


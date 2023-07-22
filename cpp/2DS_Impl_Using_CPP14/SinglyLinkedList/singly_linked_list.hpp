#ifndef __SINGLY_LINKED_LIST_TMPL__
#define __SINGLY_LINKED_LIST_TMPL__

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class SinglyLinkedList {
    public:
        class ListNode {
            T val;
            uint32_t id; // id starts from 0
            static uint32_t next_node_id;
            unique_ptr<ListNode> next;
            public:
                ListNode(const T& v, unique_ptr<ListNode> next_node=nullptr) : val {v}, id {}, next{move(next_node)} {
                    #ifdef DEBUG_MSG
                        cout << "constructed node with id: " << id << endl;
                    #endif
                } 
                ~ListNode() {
                    #ifdef DEBUG_MSG
                        cout << "destroyed node with id: " << id << endl;
                    #endif
                }           

                void set_next(unique_ptr<ListNode> node) {
                    next = move(node);
                }

                const unique_ptr<ListNode>& get_next() {
                    return next;
                }

                const T& get_val() {
                    return val;
                }
        };
        using NodeType = SinglyLinkedList<T>::ListNode;
        using NodeUniquePtrType = unique_ptr<NodeType>;

        SinglyLinkedList();
        ~SinglyLinkedList();
        void insert_before(T& val);
        NodeUniquePtrType& find_node(const T& val);
        void remove_after(const unique_ptr<ListNode>& ref);
        unsigned int size() { return sz; }
        void traverse();
    private:
        unique_ptr<ListNode> head;
        unsigned int sz;
    };

template <typename T>
uint32_t SinglyLinkedList<T>::NodeType::next_node_id = 0;

// moving her from singly_linked_list.cpp file

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

template <typename T>
SinglyLinkedList<T>::NodeUniquePtrType& SinglyLinkedList<T>::find_node(const T& val ) {
    auto  temp = head.get();
    while(temp) {
        if(temp->val==val)
            return temp;
    }
}

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

//

#endif // __SINGLY_LINKED_LIST_TMPL__
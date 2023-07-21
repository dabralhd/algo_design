#pragma once

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class SinglyLinkedList {
    public:
        class ListNode {
            T val;
            unsigned int id; // id starts from 0
            unique_ptr<ListNode> next;
            public:
                ListNode(const T& v, unique_ptr<ListNode> next_node=nullptr) : val {v}, next{move(next_node)} {
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


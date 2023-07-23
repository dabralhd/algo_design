#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__

#include <memory>
#include <cstdint>
#include <iostream>
#include <stdexcept>

using namespace std;

class DoublyLinkedList {
    struct Node {
        int32_t val;
        unique_ptr<Node> next;
        DoublyLinkedList::Node* prev;                
        uint32_t id;
        static uint32_t next_id;
        Node(int32_t v);
        ~Node();        
    };
    using t_NodeUPtr = unique_ptr<Node>;
    uint32_t sz;
    t_NodeUPtr head;
    Node* tail;
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList&) = delete;
        DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

        DoublyLinkedList(DoublyLinkedList&&);  // move ctor
        DoublyLinkedList& operator=(DoublyLinkedList&& rhs);        
        ~DoublyLinkedList();    
        void push_front(uint32_t v);
        void pop_front();
        void push_back(uint32_t v);
        void pop_back();
        uint32_t front();
        uint32_t back();
        uint32_t size() { return sz; }
};

uint32_t DoublyLinkedList::Node::next_id = 0;

DoublyLinkedList::Node::Node(int32_t v) : val {v}, next {nullptr}, prev{nullptr} {
    id = next_id++;
    cout << "Node::ctor, node_id: : " << id << endl;
}

DoublyLinkedList::Node::~Node() {
    cout << "Node::dtor, node_id: : " << id << endl;    
}

DoublyLinkedList::DoublyLinkedList() : sz {0}, head{make_unique<DoublyLinkedList::Node>(0)}, tail{new DoublyLinkedList::Node(0)} {
    cout << "DoublyLinkedList::ctor" << endl;
    tail->prev = head.get();
    head->next.reset(tail);
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& other) : sz {other.sz} {  
    cout << "DoublyLinkedList::ctor move" << endl;
    tail->prev = other.tail->prev;
    head->next.reset(other.head->next.get());

    other.tail = nullptr;
    other.head.reset();
    other.sz = 0;
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& rhs) {   // clean up target and move
    cout << "DoublyLinkedList::operator= move" << endl;
    swap(head, rhs.head);
    swap(tail, rhs.tail);
    swap(sz, rhs.sz);
    return *this;
}

DoublyLinkedList::~DoublyLinkedList() {
    cout << "DoublyLinkedList::dtor" << endl;
    tail->prev = nullptr;
    sz = 0;
}

uint32_t DoublyLinkedList::front() {
    if(sz) {
        return head->next->val;
    }
    throw underflow_error("err - list is empty");
}

uint32_t DoublyLinkedList::back() {
    if(sz) {
        return tail->prev->val;
    }
    throw underflow_error("err - list is empty");
}

void DoublyLinkedList::push_front(uint32_t v) {
    t_NodeUPtr temp = make_unique<DoublyLinkedList::Node>(v);
    temp->next = move(head->next);
    temp->next->prev = temp.get();
    temp->prev = head.get();
    head->next = move(temp);
    sz++;
}

void DoublyLinkedList::pop_front() {
    if(sz) {
        head->next = move(head->next->next);
        head->next->prev = head.get();
        sz--;
    }
}

#endif // __DOUBLY_LINKED_LIST__


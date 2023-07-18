#include <iostream>

using namespace std;

template <typename T>
class shared_ptr{
    private:
        class ControlBlock {
            private:
                T* ptr;
                int refs;
            public: 
                ControlBlock(T* p1)  :ptr {p1}, refs {1} {
                    cout << "ControlBlock allocated" << endl;
                }
                ~ControlBlock {
                    ptr = nullptr;
                    cout << "ControlBlock de-allocated" << endl;
                }
        };
    ControlBlock * cb;
    public:
        shared_ptr<T>(T* ptr=nullptr) {
            cb = new ControlBlock(ptr);
        }
        shared_ptr<T> (const shared_ptr<T>& other) {
            cb = other.cb;
            cb->refs++;
        }

        ~shared_ptr<T> () {
            if(--cb.refs==0) {
                delete cb->ptr;
                delete cb;
            }
        }        
};
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class Example   {
    public:
        Example(int d=100) : data {d} {
            cout << "created Example object" << endl;
        }

        friend ostream& operator<<(ostream& os, const Example& ex) {
            os << ex.data;
            return os;
        }

    private:
        int data;
};

// how will you implement shared pointer in C++

template <typename T>
class MyUniquePointer {
    private:
        T* ptr;
        MyUniquePointer<T>(const MyUniquePointer<T>& rhs) = delete;
        MyUniquePointer* operator=(const MyUniquePointer<T>& rhs) = delete;
   
    public:
        MyUniquePointer() : ptr { nullptr } 
        {}

        MyUniquePointer(T* p) : ptr { p }
        {}

        make_unique()

        T operator*() {
            if (ptr == nullptr)
                throw exception();
            return *ptr;
        }

        const T& operator=(const T& value) { 
            *ptr = value;
            return *ptr;
        }

};


int main() {
    #if 0 // unique_ptr

    // https://en.cppreference.com/w/cpp/memory/unique_ptr
    // https://www.geeksforgeeks.org/smart-pointers-cpp/

    cout << "Experimenting on unique pointers: "  << endl;
    int x = 10;
    unique_ptr<Example> sptr1(new Example);
    cout << "using unique pointer: " << *sptr1 << endl;

    unique_ptr<Example> sptr2;
    sptr2 = sptr1;
    cout << "using another unique pointer: " << *sptr2 << endl;

    #endif

    #if 0 // shared_ptr
    // https://www.geeksforgeeks.org/smart-pointers-cpp/

    cout << "Experimenting on share_ptr: "  << endl;
   
    shared_ptr<Example> sptr1(new Example);
    cout << "using shared_ptr: " << *sptr1 << endl;

    shared_ptr<Example> sptr2;
    sptr2 = sptr1;
    cout << "using another shared_ptr: " << *sptr2 << endl;
    #endif

    #if 1

    MyUniquePointer<int> ptr (new int);

    cout << "ptr is: " << *ptr;

    //MyUniquePointer<int> ptr2 = ptr;

    #endif

    return 0;
}
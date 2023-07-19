#include <iostream>

using namespace std;

template <typename T>
class unique_ptr {
    private:
        T* cp;
    public:
        explicit unique_ptr(T *ptr=nullptr) : cp {ptr} {}

        unique_ptr(const unique_ptr& other) = delete;

        unique_ptr& operator=(const unique_ptr& other) = delete;

        unique_ptr(unique_ptr&& other) : cp {other.cp}
        {
            other.cp = nullptr; 
        }

        unique_ptr& operator=(unique_ptr&& other) 
        {
            if(this!=&other) {
                cp = other.cp;
                delete other;
                other.cp = nullptr;
            }
            return *this;
        }

        T& operator*() {
            return *cp;
        }

        T* operator->() {
            return cp;
        }

        ~unique_ptr() {
            delete cp;
        }
};

struct MyClass {
    int a;
    int b;
    MyClass(int a=1, int b=2) : a{a}, b{b}
    {}
};

int main() {
    MyClass* ptr = new MyClass();
    unique_ptr<MyClass> up(ptr);
    cout << endl << up->a <<", " << up->b << endl;
    return 0;
}
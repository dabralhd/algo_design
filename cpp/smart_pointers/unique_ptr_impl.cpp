#include <iostream>

using namespace std;

template <typename T>
class unique_ptr {
    private:
        T* cp;
    public:
        unique_ptr<T> (T *ptr=nullptr) : cp {ptr} {}
        unique_ptr<T> (unique_ptr<T>&& up2) : cp {std::move(up2.cp)}
        {
            up2.cp = nullptr; 
        }
        unique_ptr<T> operator=(unique_ptr<T> rhs) = delete;
        T& operator*() {
            return *cp;
        }

        T* operator->() {
            return cp;
        }

        ~unique_ptr<T>() {
            delete cp;
        }
};

struct MyClass {
    int a;
    int b;
};

int main() {
    MyClass x;
    x.a = 10;
    x.b = 20;
    unique_ptr<MyClass> up(&x);
    cout << endl << up->a <<", " << up->b << endl;
    return 0;
}
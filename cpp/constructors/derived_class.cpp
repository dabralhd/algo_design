#include <iostream>
#include <memory>

using namespace std;

class Base {
    public:
        Base() {
            cout << "Base constructor" << endl;
        }

        ~Base() {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Derived constructor" << endl;
        }
        ~Derived() {
            cout << "Derived destructor" << endl;
        }
};

int main() {
    #if 0
        Base* b = new Derived();
    #endif

    #if 1
        unique_ptr<Base> b = make_unique<Derived>();
    #endif
    return 0;
}
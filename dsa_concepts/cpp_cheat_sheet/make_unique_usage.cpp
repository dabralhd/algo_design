#include <iostream>
#include <memory>

using namespace std;

class A {
    int m, n;
    public:
    A(int _m, int _n) : m{_m} , n {_n} {}
};

int main() {
    cout << "creating A()" << endl;
    // basic form of make_unique
    unique_ptr<A> up = make_unique<A>(2,3);
    cout << "object creation complete" << endl;

    // 


    return 0;
}
#include <iostream>
#include <memory>
#include <array>
#include <algorithm>

using namespace std;

class A {
    public:
        int val;
        A(int v) : val {v} {}
        A() : val{0} {}

};

int main() {
    unique_ptr<A> ptr1(new A());
    cout << ptr1->val << endl;

    unique_ptr<A> ptr2(new A(100));        
    cout << ptr2->val << endl;

    array<int, 5> arr {1, 2, 3,4,5};
    for(const auto x : arr)
        cout << x << " ";
    cout << endl;

    for_each(arr.begin(), arr.end(), [](int& x) { x += 2;});
    for(const auto x : arr)
        cout << x << " ";    


}
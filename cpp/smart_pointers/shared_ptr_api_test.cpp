#include <iostream>
#include <memory>

using namespace std;

void multiply_by2(shared_ptr<int> sp) {
    *sp *= 2;    
}

int main() {
    shared_ptr<int> sp1 = make_shared<int>(100);
    cout << "sp1: " << *sp1 << endl;
    multiply_by2(sp1);
    cout << "sp1: " << *sp1 << endl;
    return 0;
}
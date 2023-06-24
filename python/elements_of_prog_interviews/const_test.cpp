#include <iostream>
#include <memory>

using namespace std;

void t1(const int& i) {
    //i++; // compile time error
}

void t2(const int* pi) {
    //++*pi; // compile error
}

unique_ptr<int> t3(unique_ptr<int> upi) {
    ++*upi;
    return upi;
}

void t4(const unique_ptr<int>& pi) {
    ++*pi;
    //pi.reset();
}

void t5(const int& i) {
    //i++;
}

int main() {
    int num = 10;
    t1(num);
    t2(&num);

    unique_ptr<int> up  {make_unique<int>(100)};
    up = t3(move(up));
    cout << *up << endl;
    t4(up);
    unique_ptr<int>& up2 = up;
    cout <<"*up2: " << *up2 << endl;

    //cout << *up << endl;

    //cout << *up << endl;

    return 0;
}
/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class X {
    public:
    int *val;
    X() : val {nullptr} {}
    X(const int cval) : val {new int(cval)} {}    
    X(const X& other) : X(other.get_val()) {

        cout << "copy constructor" << endl;
    }
    
    X(X&& other) {
        cout << "move constructor" << endl;
        if(other.val) {
            val = other.val;
            other.val = nullptr;
        }
    }    
    
    int get_val() const {return *val;}

    int incr() {return ++*val;}
};

int ix = 100;
X x(200);

unique_ptr<X> f(unique_ptr<X> x) {
    x->incr();
    return x;
}

int main()
{
    unique_ptr<X> up1 = make_unique<X>(move(x));
    cout << "up1 value: " << up1->get_val() << endl;
    //cout << "x: " << x.get_val() << endl;
    
    cout <<"incrementing up1:" << endl;
    up1->incr();
    cout << "up1 value: " << up1->get_val() << endl;
    //cout << "x: " << x.get_val() << endl;    

    auto up2 = f(move(up1));
    cout << "up2 value: " << up2->get_val() << endl;
    
    return 0;
}
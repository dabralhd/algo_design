#include <iostream>
#include <thread>

using namespace std;

void incr(int&);
void test_pass_ref_params();
void test_basic_api();
void test_pass_ref_params();

int main() {
    test_basic_api();
    //test_pass_ref_params();
}

void test_basic_api() {
    cout << "thread::hardware_concurrency: " << thread::hardware_concurrency() << endl;
}

void incr(int &count) {
    unsigned long i = 0;
    while(i!=100000000L) i++;
    count++;
    cout << "- <incr>" << count << endl;
}

void test_pass_ref_params() {
    int counter = 99;
    cout << "- <test_pass_ref_params> counter: " << counter << endl;    
    thread t(incr, ref(counter));
    cout << "- <test_pass_ref_params> counter: " << counter << endl;
    t.join();
    cout << "- <test_pass_ref_params> counter: " << counter << endl;
}


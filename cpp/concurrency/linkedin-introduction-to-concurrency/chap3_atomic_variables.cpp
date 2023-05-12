#include <iostream>
#include <thread>
#include <atomic>

using namespace std;
atomic<int> count {0};

void increment() {
    for(int i=0; i<100000; i++)
        count++;
} 

int main() {
    thread t1(increment);
    thread t2(increment);    
    t1.join();
    t2.join();
    printf("count = %d\n", count.load());
    return 0;
}
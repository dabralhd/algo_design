#include <cstdio>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
unsigned int count = 0;
mutex m;

void increment() {
    for(int i=0; i<10000; i++) {
        this_thread::sleep_for(chrono::microseconds(50));
            m.lock();
            count++;
            m.unlock();
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);    
    t1.join();
    t2.join();
    printf("count is: %u\n", count);       
}
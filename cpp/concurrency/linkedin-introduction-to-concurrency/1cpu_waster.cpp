#include <iostream>
#include <thread>
#include <cstdio>
#include <unistd.h>
#include <chrono>
#include <limits>
#include <vector>

using namespace std;

int cpu_waster() {
    printf("cpu waster: 0x%x\n", this_thread::get_id());
    long count = 0;
    while(count!=numeric_limits<long>::max())
        count++;
    return count;
    //while(1);
}

int main() {
    printf("process id: 0x%u\n", getpid());

    const int k_thread_count = 10;
    vector<thread> vt;
    for(int i=0; i<k_thread_count; i++) {
        vt.push_back(thread(cpu_waster));
    }
   // while(true) {
        //this_thread::sleep_for(chrono::seconds(10));
    //}

    for(int i=0; i<k_thread_count; i++) {
        vt[i].join();
    }
}
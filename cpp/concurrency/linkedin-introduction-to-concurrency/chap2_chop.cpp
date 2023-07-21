#include <iostream>
#include <thread>
#include <string>

using namespace std;

bool flag = true;

void chop(string vegetable, bool short_nap) {
    printf("<chop> chopping vegetable: %s\n", vegetable.c_str());
    unsigned long pieces = 0;
    while(flag) {
        pieces++;
#if 0
        if(short_nap)
            this_thread::sleep_for(50ms);
        else
            this_thread::sleep_for(100ms);
#endif            
    }
    printf("<chop> chopped %s till %ul pieces\n", vegetable.c_str(), pieces);
}

int main() {
    thread t1(chop, "carrots", false);
    thread t2(chop, "onion", true);    
    this_thread::sleep_for(std::chrono::seconds(5));
    flag = false;
    t1.join();
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    t2.join();
}
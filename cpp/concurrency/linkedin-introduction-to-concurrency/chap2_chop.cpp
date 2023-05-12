#include <iostream>
#include <thread>
#include <string>

using namespace std;

bool flag = true;

void chop(string vegetable, bool short_nap) {
    cout << "<chop> chopping vegetable: " << vegetable << endl;
    unsigned long pieces = 0;
    while(flag) {
        pieces++;
#if 0
        if(short_nap)
            this_thread::sleep_for(40ms);
        else
            this_thread::sleep_for(100ms);
#endif            
    }
    cout << "<chop> chopped " << vegetable << " till " << pieces << " pieces." << endl;
}

int main() {
    thread t1(chop, "carrots", true);
    thread t2(chop, "onion", false);    
    this_thread::sleep_for(std::chrono::microseconds(2500));
    flag = false;
    t1.join();
    t2.join();
}
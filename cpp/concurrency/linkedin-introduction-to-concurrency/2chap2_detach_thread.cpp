#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void background() {
    cout << "background thread id: " << this_thread::get_id() << endl;
    while(true);
}

int main() {
    thread t(background);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "main thread id: " << this_thread::get_id() << endl;
    //t.join();
}
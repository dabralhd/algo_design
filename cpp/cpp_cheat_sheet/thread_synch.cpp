#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void myThread(int x) {
    cout << "Inside my thread: " << x << endl;
}

void cthread(const int id, int x) {
    cout << ">>cthread: " << id << endl;

    for(int i=0; i<100*x; ++i) {
        cout << "-cthread " << x << ": " << i << endl;
    }

    cout << "<<cthread #" << id << endl;
}

int main() {
    #if 0
    // basic example
    thread th(&myThread, 100);
    th.join();
    #endif

    #if 1
    // advanced example
    vector<thread> th_pool;
    const int Th_count = 10;

    for (int i=0; i<Th_count; ++i) {
        th_pool.push_back(thread(cthread, i));
    }

    for (int i=0; i<Th_count; ++i) {
        th_pool[i].join();
    }
    
    #endif    

    cout << "thread execution complete." << endl;
    return 0;
}
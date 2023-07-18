#include <iostream>
#include <array>
#include <stack>

using namespace std;


void init(array<stack<int>, 3>& pegs, int ring_count) {
    for(int i=ring_count; i>0; i--) {
        pegs[0].push(i);
    }
}

void solve(array<stack<int>, 3>& pegs, 
           const int from,
           const int to,
           const int usage,
           const int ring_count) {            
            if(ring_count) {
                solve(pegs, from, usage, to, ring_count-1);
                cout << "moving r_" << pegs[from].top() << " from T" << from << " to T" << to << endl;                 
                pegs[to].push(pegs[from].top());
                pegs[from].pop();
                solve(pegs, usage, to, from, ring_count-1);
            }

        }

void solve(int ring_count) {
    array<stack<int>, 3> pegs;    
    init(pegs, ring_count);
    solve(pegs, 0, 2, 1, ring_count);
}        

void test_tower_of_hanoi() {
    solve(3);
}

int main() {
    test_tower_of_hanoi();
    return 0;
}
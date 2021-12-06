#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * 
 */
void percolate_down(vector<int>& v, int i, int heapsize) {
    int parent = i;
    int child = parent*2 + 1;
    int key = v[parent];

    while(v[child] < v[parent] && child<heapsize) {
        if( child+1<heapsize && v[child+1]<v[child]) {
            child++;
        }
        if(v[child] < v[parent]) {
            swap(v[parent], v[child]);
            parent = child;
            child = parent*2 + 1;
        }        
    }
    v[parent] = key;
}

void build_heap(vector<int>& v) {
    for(int i=v.size()/2 - 1; i>=0; --i) {
        percolate_down(v, i, v.size());
    }
}

int main() {
    vector<int> v = {4, 2, 8, 0, 1, 100, 90, -2};

    build_heap(v);

    for(int i=0; i<v.size(); ++i) {
        swap(v[v.size()-1-i], v[0]);
        percolate_down(v, 0, v.size()-1-i);
    }

    for(const auto& x : v)
        cout << x << endl;
    return 0;
}
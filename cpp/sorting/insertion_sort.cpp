#include <iostream>


void insertion_sort(vector<int>& v) {
    for(int i=1; i<v.size(); ++i) {
        int key = v[i];
        for(int j=i; j>0 && key < v[j-1]; --j) {
            v[j] = v[j-1];
        }
        v[j] = key;
    }
}
#include <iostream>
#include <vector>

using namespace std;

void print_elements(vector<int> vec, string desc) {
    cout << desc << ": " << endl;
    cout << "- size:  " << vec.size() << endl;    
    
    cout << "now iterating through elements: " << endl;
    for(auto e : vec) {
        cout << e << " ";
    }

    cout << endl;
}

vector<int> get_empty_vector() {
    vector<int> vec {};
    return vec;
}

int main() {
    vector<int> empty {};    
    print_elements(empty, string("empty"));
    
    vector<int> four_elems {1, 2, 3, 4};
    print_elements(four_elems, "four elements");

    print_elements(get_empty_vector(), string("get_empty_vector()"));

    return 0;
}
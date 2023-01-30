#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myfunc(const int& x) {
    cout <<x << endl;
}

int main() {
    cout << "enter numbers: " << endl;
    int x = 0;
    vector<int> v;

    while ( cin >> x && x>=0 ) {
        v.push_back(x);
    }

    for_each(v.begin(), v.end(), [](int& x) { 
        x = x*x;
    });

    for(const auto& x : v) 
        cout << x << endl;

    return 0;
}
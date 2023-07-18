#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size {};
    cout << "enter size: ";
    cin >> size;
    vector<int> vi(size);

    cout << "size of vector is: " << vi.size() << endl;
    cout << "using sizeof operator, vector size is: " << sizeof(vi) << endl;    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> get_numbers_from_file(string file_int) {
    ifstream ifs(file_int, ios::in);
    vector<int> vn;

    if (!ifs) {
        cerr << "error while reading file: " << file_int << endl;
        return vn;
    }

    int num;
    while (ifs >> num) {       
        clog << num << endl;
        vn.push_back(num);    
    }

    ifs.close();
    return vn;    
}

template <typename T>
void print_vector(const vector<T> vt){
    for (auto x : vt)
        cout << x << endl;
}

int main() {
    auto vi = get_numbers_from_file("numbers.txt");    
    cout << "before sorting: " << endl << endl;
    print_vector(vi);

    cout << "after sorting: " << endl << endl;
    sort(vi.begin(), vi.end());
    print_vector(vi);

    cout << "after sorting on the basis of square function: " << endl << endl;
    sort(vi.begin(), vi.end(), [](int left, int right){return left*left < right*right;});
    print_vector(vi);    


    return 0;
}
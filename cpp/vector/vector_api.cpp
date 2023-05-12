#include <iostream>
#include <iterator>
#include <vector>
#include <ostream>

using namespace std;

void print_info(const vector<int>& vi) {
    cout << "vector size: " << vi.size() << endl;
    cout << "vector capacity: " << vi.capacity() << endl;
}

void test_size_capacity();
void test_ostream_iterator();

int main() {
    test_size_capacity();
    //test_ostream_iterator();
    return 0;
}

void test_size_capacity() {
    vector<int> vi;
    cout << "Initial state: \n";
    print_info(vi);

    cout << "reserving 4 slots:\n";
    vi.reserve(4);
    print_info(vi);

    cout << "push_back: value 15 " << endl;
    vi.push_back(15);
    cout << "first element: " << vi.front() << endl;
    print_info(vi);

    cout << "insert: value 10 at position begin()" << endl;
    vi.insert(vi.begin(), 10);
    cout << "first element: " << vi.front() << endl;
    print_info(vi);


    cout << "push_back: " << endl;
    vi.push_back(2);
    print_info(vi);

    cout << "push_back: " << endl;
    vi.push_back(3);
    print_info(vi);

    cout <<"erase: " << endl;
    vi.erase(vi.begin(), vi.begin()+2);
    print_info(vi);

    cout << "clear: " << endl;
    vi.clear();
    print_info(vi);
}

void test_ostream_iterator() {
    cout << "-- test_ostream_iterator --" << endl;
    ostream_iterator<int> osi {cout, "this->"};
    vector<int> vi {1,2,3,4,5};
    copy(vi.cbegin(), vi.cend(), osi);
}

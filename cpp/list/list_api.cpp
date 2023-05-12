#include <list>
#include <iostream>

using namespace std;

void list_push_front_splice_test();

int main() {
    list_push_front_splice_test();
    return 0;
}

ostream& operator<<(ostream& os, const list<int> l) {
    for(const auto& elem : l) {
        os << elem << "->";
    }

    os << "x" << endl;
    return os;
}

void list_push_front_splice_test() {
    list<int> first;
    first.push_front(1);
    first.push_front(2);
    first.push_front(3);
    first.push_front(4);
    cout << "printing list first:" << endl << first;

    list<int> second {10, 20, 30};
    cout << "printing list second: " << endl << second;

    cout << "testing splice operation: " << endl;
    first.splice(first.begin(), second, second.begin(), next(second.begin(), 2));
    cout << "printing list first after splicing" << endl << first;


}

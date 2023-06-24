#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Comparator {
    bool operator()(const int & lhs, const int & rhs) const {
        return lhs < rhs;
    }

};

// look-up of the value associated with key
char const& operator[]( int const& key ) const {
    auto it=m_map.upper_bound(key);
    if(it==m_map.begin()) {
        return m_valBegin;
    } else {
        return (--it)->second;
    }
}

void test() {
    map<int, char, Comparator> m {{1, 'B'}, {3, 'A'}};
    constexpr char K_value_lowest = 'X';

    //find lowest value in the datastructure
    for(auto elem : m) {

    }

    // 1
    int k = -2;
    map<int, char>::iterator itr_l;
    map<int, char>::iterator itr_u;

    for(k=-2; k<=5; k++) {    
        itr_l = m.lower_bound(k);
        itr_u = m.upper_bound(k);        
        cout << "[k = " << k << "]:";
        if(itr_l!=m.end())
            cout << "lower bound: " << itr_l->second<< ", ";
        else
            cout << "lower bound: " << K_value_lowest<< ", ";

        if(itr_u!=m.end())
            cout << "upper bound: " << itr_u->second<< ", ";
        else
            cout << "upper bound: " << K_value_lowest<< ", ";


        cout << endl;        
    }

}

int main() {
    test();
    return 0;
}
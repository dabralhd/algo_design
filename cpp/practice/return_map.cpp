#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, unsigned int> get_char_count(string s) {
    unordered_map<char, unsigned int> m;

    for(const auto & ch : s) {
        if(m.find(ch)==m.end()) {
            m[ch] = 1;
        } else {
            m[ch] += 1;
        }
    }
    return m;
}

void test(string s) {
    auto m = get_char_count(s);
    for(auto p : m) {
        cout << p.first << ": " << p.second << endl;
    }
}

void test1() {
    test("blackdogs are black");
    cout << "******" << endl;

    test("ducks are white");
    cout << "******" << endl;    
}

int main() {
    test1();
    return 0;
}
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    unordered_map<string, string> my_unordered_map;
    my_unordered_map["abc"] = "dfe";
    my_unordered_map["xyz"] = "xy";
    //my_unordered_map["xyz"] = "abc";

    for(const auto& p : my_unordered_map) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
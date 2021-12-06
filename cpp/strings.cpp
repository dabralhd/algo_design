#include <iostream>

using namespace std;

int string_io_test() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 <<endl;

    return 0;
}

int get_lines() {
    string line;

    while(getline(cin, line)) {
        cout << line << endl;
        if(line.empty())
            break;
    }
    return 0;
}

int main() {
    //return string_io_test();
    return get_lines();
    
}
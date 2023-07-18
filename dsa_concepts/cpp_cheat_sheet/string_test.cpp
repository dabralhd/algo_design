#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "world";

    cout << s1 << " " << s2 << endl;

    s1 = move(s2);
    s2 += " modified";

    cout <<"after modification: " << endl << s1 << endl << s2 << endl;
    return 0;
}
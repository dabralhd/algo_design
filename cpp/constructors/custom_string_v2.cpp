/* CustomString class version 2.0 - using smart pointer */

#include <iostream>
#include <cstring>
#include <vector>
#include <memory>

using namespace std;

/** class for representing v1 of custom string object using c++03 features
 * 
 */ 
int custom_strlen(const char* str) {
    int count = 0;
    while(*str++)
        ++count;
    return count;
}

class String {
    private:
        int m_size;
        char *ptr;
    public:
        CustomString
}

int main() {    
    #if 0
        char str[] = "hello";
        cout << custom_strlen(str) << endl;  
    #endif

    #if 1
    CustomString str("Hello");
    cout << str << endl;
    #endif

    #if 0
    vector<CustomString> v(2, "Hello");
    for(const auto& str : v) 
        cout << str << endl;
    #endif

    return 0;
}
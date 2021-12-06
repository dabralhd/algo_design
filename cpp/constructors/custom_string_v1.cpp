/* CustomString class version 1.0 */

#include <iostream>
#include <cstring>
#include <vector>

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

class CustomString {
    private:
        int m_size;
        char* m_ptr;
    public:
        const char* getPtr() { return m_ptr; }
        CustomString() : m_size { 0 }, m_ptr { nullptr } { 
            cout << "Default constructor" << endl;
        }

        CustomString(const char* str) {
            cout << "Parameterized constructor" << endl;
            m_size = custom_strlen(str);
            m_ptr = new char[m_size + 1];
            memcpy(m_ptr, str, m_size);
            m_ptr[m_size] = 0;
        }

        CustomString(const CustomString& other) : 
                                m_size { other.m_size }, 
                                m_ptr { nullptr } { 
            cout << "Copy constructor" << endl; 
            m_ptr = new char[m_size + 1];
            memcpy(m_ptr, other.m_ptr, m_size + 1);
        }

        ~CustomString() {
            cout << "Destructor" << endl;
            delete [] m_ptr;
            m_size = 0;
        }

        friend ostream& operator<<(ostream&  stream, const CustomString& str) {
           stream << "streaming object: " << str.m_ptr << endl;
           return stream;
        }
};

int main() {    
    #if 0
        char str[] = "hello";
        cout << custom_strlen(str) << endl;  
    #endif

    #if 0
    CustomString str("Hello");
    cout << str << endl;
    #endif

    #if 1
    vector<CustomString> v(2, "Hello");
    for(const auto& str : v) 
        cout << str << endl;
    #endif

    return 0;
}
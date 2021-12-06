#include <iostream>

using namespace std;

class Length  {
    public:
        /* explicit */ Length(float len=5.0f) : length { len } 
        {}

        bool operator==(const Length& rhs) { 
            if( length == rhs.length )
                return true;
            return false;
        }

    private:
        float length;
};

int main() {
    Length l1(5.0f);

    if( l1 == 5.0f )
        cout << "same" << endl;
    else
        cout << "not same" << endl;
    
    return 0;
}
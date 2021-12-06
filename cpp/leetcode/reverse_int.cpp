#include <iostream>
#include <exception>
#include <limits>

using namespace std;

class Solution {
public:
    inline int signof(int x) {
        return (x < 0) ? (-1) : (+1);
    }

    int reverse(int x) {
        int sign = signof(x);
        int opposite_sign = sign * -1;
        int y = 0;
        //x = x*sign;
        int z = INT_MAX;

        while(x) {       
            int units_place = x % 10;                                            
            if ((y > numeric_limits<int>::max() / 10) ||
                ((y == numeric_limits<int>::max() / 10) && (units_place > 7)) ||
                ((y < numeric_limits<int>::min() / 10) && (units_place < -8)))
                    return 0;

                             
                x = x / 10;
                y = y*10 + units_place;
        }       

        y = y * sign;
        return y;
    }
};


int main() {
    Solution sol;

    int x = 1534236469;
    //int x = 153;
    cout << "reversing input string: " << sol.reverse(x) << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Roman {
public:
    int romanToInt(string num) {
        int n = 0;
        for(int i=0; i<num.size(); i++) {
            switch(num[i]) {
                case 'M':
                    n += 1000;
                    break;
                case 'D':
                    n += 500;
                    break;
                case 'C':
                    if (num.size()>i+1 && num[i+1]=='M') {
                        n += 900;
                        i++;
                    } else if (num.size()>i+1 && num[i+1]=='D') {
                        n += 400;
                        i++;
                    } else {
                        n += 100;
                    }

                    break;
                case 'L':
                    n += 50;
                    break;
                case 'X':
                    if (num.size()>i+1 && num[i+1]=='L') {
                        n += 40;
                        i++;
                    } else if (num.size()>i+1 && num[i+1]=='C') {
                        n += 90;
                        i++;
                    } else {
                        n += 10;
                    }
                    break;
                case 'V':
                    n += 5;
                    break;
                case 'I':
                    if (num.size()>i+1 && num[i+1]=='V') {
                        n += 4;
                        i++;
                    } else if (num.size()>i+1 && num[i+1]=='X') {
                        n += 9;
                        i++;
                    } else {
                        n += 1;
                    }
                    break;
            }
        }
        return n;
        
        
    }
};

int test_str_to_int(string s) {
    cout << endl << "given string: " << s << endl;
    cout << "equivalent roman number: " << Roman().romanToInt(s) << endl;
} 

int main() {
    test_str_to_int("XX");
    test_str_to_int("IX");    
    test_str_to_int("CMXVII");    
}
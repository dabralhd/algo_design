#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    vector<string> str;

    cin >> T;  
    str.resize(T);

   // after reading above variable, ignore all characters till '\n' is encountered
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    for (int tc=0; tc<T; tc++) {        
        getline(cin, str[tc]);
    }
    //cout << str;    

    for (int tc=0; tc<T; tc++) {
        string even;
        string odd;

        for(unsigned int i=0; i<str[tc].size(); i++) {
        // cout << i << endl;

            if(i%2==0)   { // even index
            even = even + str[tc][i];
            } else {
                odd = odd + str[tc][i];
            }
        } 

        cout << even << " " << odd << endl;
    }
    
    return 0;
}

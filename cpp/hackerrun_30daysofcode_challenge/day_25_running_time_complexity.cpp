#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T=0;
    cin >> T;
    cin.ignore(numeric_limits<int>::max(), '\n');
    
    vector<int> input(T);
    for(int i=0; i<T; i++) {
        int x = 0;
        cin >> x;
        input.push_back(x);        
    }
    
    for(int i=0; i<T; i++) {        
        unsigned int square_root = sqrt(input[i]);
        cout << "input, square root: " << input[i] << "," << square_root << endl;
        bool is_prime = true;
        for(int j=2; j<=square_root; j++) {
            if (input[i]%j == 0) {
                is_prime = false;
                break;
            }            
        }
        if(is_prime) 
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }    
    return 0;
}

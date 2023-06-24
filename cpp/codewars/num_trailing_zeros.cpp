#include <iostream>
#include <cassert>
#include <array>

using namespace std;

long zeros(long n) {
  unsigned long num2 = 0;
  unsigned long num5 = 0;
  for(long i=1; i<=n; i++) {
    int x= i;
    while (x % 2 == 0) {      
      num2++;
      x /= 2;
    } 
  
    while (x % 5 == 0) {
      num5++;      
      x /= 5; 
    }
   }
  
  return (num2 < num5)? num2 : num5;
}

/**
 * use memoization for speed gain
*/
long zeros_DP(long n) {
    constexpr long K_MAX_PROB_SIZE = 1000000000;
    if (n > K_MAX_PROB_SIZE)
        return -1;
    // 2d vector to memoize factors. 
    // 3 fields are valid, fact5, fact2
    array<array<unsigned long, 3>, K_MAX_PROB_SIZE + 1> factors; 
    for(long i=0; i<K_MAX_PROB_SIZE + 1; i++) {
        factors[i][0] = 0;
        factors[i][1] = 0;
        factors[i][2] = 0;
    }
    factors[0][0] = factors[1][0] = 1;
    
    for(long i=2; i<=n; i++) {    
        unsigned long num2 = 0;
        unsigned long num5 = 0;        
        int x = i;   
        while ((!factors[i][0]) && (x % 5 == 0)) {      
            num5++;
            x /= 5;

            if(factors[x][0] == 1) {            
                factors[i][1] = num5 + factors[x][1];
                factors[i][2] = num2 + factors[x][2];     
                factors[i][0] = 1;   
                break;        
            }
        } 
    
        while ((!factors[i][0]) && (x % 2 == 0)) {
            int x = i;   
            while (x % 2 == 0) {      
                num2++;
                x /= 2;

                if(factors[x][0] == 1) {
                    factors[i][1] = num5 + factors[x][1];
                    factors[i][2] = num2 + factors[x][2];        
                    factors[i][0] = 1;
                    break;
                }
            }
        }
        factors[i][0] = 1; // set factors of ith entry to valid (i.e. 1)
    }

    for(int i=2; i<=n; i++) {
        factors[i][1] += factors[i - 1][1] ;
        factors[i][2] += factors[i - 1][2] ;        
    }
  
    return (factors[n][1] < factors[n][2])? factors[n][1] : factors[n][2];
}

void test_case(const int number, const int num_zeros) {
    cout << "test_case" << endl;    
    assert(zeros(number) == num_zeros);
    cout << "number of zeros in factorial(" << number <<"): " << zeros(number) << ", test passed for " << number << endl;
}

void test() {
    test_case(0, 0);
    test_case(6, 1);
    test_case(30, 7);
    test_case(100, 24);
    test_case(1000, 249);
    test_case(100000, 24999);
    test_case(1000000000, 249999998);
}

void test_case_DP(const int number, const int num_zeros) {
    cout << "test_case_DP" << endl;
    assert(zeros_DP(number) == num_zeros);
    cout << "number of zeros in factorial(" << number <<"): " << zeros(number) << ", test passed for " << number << endl;
}

void test_DP() {
    //test_case_DP(0, 0);
    test_case_DP(6, 1);
    test_case_DP(30, 7);
    test_case_DP(100, 24);
    test_case_DP(1000, 249);
    test_case_DP(100000, 24999);
    test_case_DP(1000000000, 249999998);
}

int main() {
    test_DP();
    return 0;
}
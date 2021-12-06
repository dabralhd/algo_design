#include <bits/stdc++.h>


using namespace std;

/* 
- problem statement https://www.hackerrank.com/challenges/30-conditional-statements/problem
Objective
In this challenge, we learn about conditional statements. Check out the Tutorial tab for learning materials and an instructional video.

Task
Given an integer, , perform the following conditional actions:

If N is odd, print *Weird*
If N is even and in the inclusive range of 2 to 5, print *Not Weird*
If N is even and in the inclusive range of 6 to 20, print *Weird*
If N is even and greater than 20, print *Not Weird*
Complete the stub code provided in your editor to print whether or not  is weird.

Input Format

A single line containing a positive integer, .

Constraints

Output Format

Print Weird if the number is weird; otherwise, print Not Weird.

Sample Input 0

3
Sample Output 0

Weird
Sample Input 1

24
Sample Output 1

Not Weird

Explanation

Sample Case 0: 
 is odd and odd numbers are weird, so we print Weird.

Sample Case 1: 
 and  is even, so it is not weird. Thus, we print Not Weird.
*/


int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(N%2 == 1) {
        cout <<"Weird";
    } else if (N%2 == 0) {
        if( (N >= 2) && (N <= 5) ) {
            cout << "Not Weird";
        } else if( (N >= 6) && (N <= 20) ) {
            cout <<"Weird";
        } else if(N >= 20) {
            cout << "Not Weird";
        }
    }

    return 0;
}

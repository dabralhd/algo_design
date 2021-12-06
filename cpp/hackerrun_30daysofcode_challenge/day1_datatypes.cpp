#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int j = 0;
    double num = 0.0;
    string str = "";      
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> j; 
    cin >> num;
    cin.ignore(); 
    getline(cin, str);   
   
    // Print the sum of both integer variables on a new line.
     j += i;
     cout << j << endl;       
    
    // Print the sum of the double variables on a new line.
    num += d;
    cout << setprecision(2) << num << endl;
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    str = s + str;
    cout << str << endl;

    return 0;  
}
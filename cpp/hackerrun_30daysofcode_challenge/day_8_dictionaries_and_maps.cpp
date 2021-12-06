#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n = 0;
    long int phone_num = 0;
    string name;

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    

    map<string, int> phonebook;

    while(n--) {

	    cin >> name >> phone_num;
	    //cout << name << " " << phone_num << endl;
	    phonebook[name] = phone_num;

    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;

    while(getline(cin, line)) {
	    if( ! line[0])
		    break;
	    /*cout << line << endl;*/

	    if(phonebook[line]) 
		    cout << line <<"=" << phonebook[line] << endl;
            else
		    cout << "Not found" << endl;

    }

    return 0;
}

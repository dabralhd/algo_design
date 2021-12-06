#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

enum t_dmy {DAY, MONTH, YEAR};


// string format: ddmmyyyy
 vector<int> getDate(vector<string> s) {

        vector<int> date(3);
        date[DAY] = stoi(s[0]);
        date[MONTH] = stoi(s[1]); 
        date[YEAR] = stoi(s[2]);   

        return date; 
 }

// calculate simple difference between two dates: d1-d2
vector<int> get_simple_diff(vector<int> start, vector<int> end) {
	vector<int> diff(3);
	diff[DAY] = end[DAY] - start[DAY];
	//cout << end[MONTH] << " " << start[MONTH] << endl;
	diff[MONTH] = end[MONTH] - start[MONTH];
	diff[YEAR] = end[YEAR] - start[YEAR];

	return diff;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //vector<string> returned_date(3);
    //vector<string> due_date(3);
    vector<int> rd(3);
    vector<int> dd(3);

    for(int i=0; i<3; i++) {
    	//getline(cin, returned_date[i]);
	cin >> rd[i];
    }

    cin.ignore(numeric_limits<int>::max(), '\n');

    for(int i=0; i<3; i++) {
    	//getline(cin, due_date[i]);
	cin >> dd[i];
    }

    //cout << returned_date << endl;
    //cout << due_date << endl;  

    //rd = getDate(returned_date);
    ///dd = getDate(due_date);  

    vector<int> diff;
    diff = get_simple_diff(dd, rd);

    if(diff[YEAR] > 0) {   // difference is  in years year
        cout << 10000 << endl;
    } else if(diff[YEAR]==0 && diff[MONTH]>0) {
        cout << 500*diff[MONTH] << endl;
    } else if(diff[YEAR]==0 && diff[MONTH]==0 && diff[DAY]>0){
        cout << 15*diff[DAY] << endl;
    } else {
        cout << 0 << endl;
    }


    return 0;
}

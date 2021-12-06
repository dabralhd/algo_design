#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> bin_num;
    unsigned int remainder = 0;

    while (n>0) {
	    remainder = n % 2;
	    bin_num.push_back(remainder);
	    n = n / 2;
    }

    reverse(bin_num.begin(), bin_num.end());

    // now find consecutive ones
    unsigned int cns_ones = 0;  // consecutive ones
    unsigned int max_ones = 0;  // maximum number of ones
    unsigned int prev = bin_num[0];
    if (prev ==1)
	    cns_ones = 1;
    for(unsigned int i=1; i<bin_num.size(); i++) {

	    unsigned int cur = bin_num[i];

            if(cur == 1) {
		    if(prev == 1) {
			    ++cns_ones;
		    } else {  // cur == 1, and prev == 0
			    cns_ones = 1;
		    }
	    } 

	    
	  if (cns_ones > max_ones)
	    max_ones = cns_ones;

	  prev = cur;
    }
    cout << max_ones << endl; 

}

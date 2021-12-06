#include <iostream>
#include <string>
#include <ostream>
#include <limits>
#include <cstdlib>

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    unsigned long count_a = 0;
    int len = s.size();
    int i = 0;
    
    // find count of 'a' in one occurrence of s
    while(i != len) {
        if(s[i%len] == 'a')
            ++count_a;
        ++i;
    }

    // total number of 'a' in n/len repeatations
    count_a *= n/len;

    //now count number of 'a' in n%len chars
    int j = 0;
    while(j != n%len) {
        if(s[j] == 'a')
            ++count_a;
        ++j;
    }

    return count_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

    fout.close();

    return 0;
}

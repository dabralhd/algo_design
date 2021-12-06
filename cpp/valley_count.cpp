// Counting Valleys
// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */


int countingValleys(int steps, string path) {    
    enum hike_state {sea_level, valley, hill};
    hike_state prev_state = sea_level;
    hike_state cur_state = sea_level;

    int level = 0;
    int step_num = 0;
    int valley_count = 0;

    for(int step_num=0; step_num<steps; step_num++) {
        prev_state = cur_state;
        if(path[step_num]=='D') {
            level--;
        } else if(path[step_num]=='U') {
            level++;
        }

        if(level == 0) {
            cur_state = sea_level;
        } else if (level < 0) {
            cur_state = valley;
        } else {
            cur_state = hill;
        }

        if ((prev_state == valley) && (cur_state == sea_level)) {
            valley_count++;
        }
    }

    return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

#include <bits/stdc++.h>

// problem description: https://www.hackerrank.com/challenges/closest-numbers/problem

using namespace std;

vector<string> split_string(string);

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
	sort(arr.begin(), arr.end());

	// find minimum diff between two adjacent elements
	auto min_diff = numeric_limits<int>::max();
	auto first = arr[0];
	for(vector<int>::iterator it=arr.begin()+1; it != arr.end(); it++) {
		auto second = *it;
		if(abs(second-first) < min_diff) {
			min_diff = abs(second-first);
		}

		first = second;
	}

	// now that we have the min_diff, put all the adjacent pairs in the output vector if there absolute(diff) is equal to min_diff
	vector<int> output;
	first = arr[0];
	for(vector<int>::iterator it=arr.begin()+1; it<arr.end(); it++) {
		auto second = *it;
		if(abs(second-first) == min_diff) {
			output.push_back(first);
			output.push_back(second);
		}
        first = second;
	}

	for(auto i : output)
		cout << i << " ";
	cout <<endl;

	return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

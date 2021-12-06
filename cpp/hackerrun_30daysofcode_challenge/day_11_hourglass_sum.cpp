#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 * calculate sum of hourglass whose top-left corner is at point (i,j)
 */

int get_hourglass_sum(const vector<vector<int>> &arr, const int &row, const int &col) {
	int sum = 0;
	
	sum += arr[row][col] + arr[row][col+1] + arr[row][col+2];  // first row of hourgloass
	sum += arr[row+1][col+1];   // second row of hourgloass
	sum += arr[row+2][col+0] + arr[row+2][col+1] + arr[row+2][col+2];  // third row of hourgloass

	return sum;
}



int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int sum[4][4];
    int max_i = -1;
    int max_j = -1;
    int max_sum = numeric_limits<int>::min();

    for(unsigned int i=0; i<4; ++i) {            
	    for(unsigned int j=0; j<4; ++j) {
		    sum[i][j] = get_hourglass_sum(arr, i, j);
		    if( sum[i][j] > max_sum) {
			    max_sum = sum[i][j];
			    max_i = i;
			    max_j = j;
		    }
			    
	    }
    }

    for(int i=0; i<4; i++) {
	    for(int j=0; j<4; j++) {
		    //cout << sum[i][j] << " ";
	    }
	    //cout << endl;
    }

    cout << max_sum;

    return 0;
}

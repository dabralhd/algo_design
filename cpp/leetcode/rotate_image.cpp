class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix
        for(auto i=0; i<matrix.size(); i++) {
            for(auto j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the matrix
        for(auto i=0; i<matrix.size(); i++) {
            auto begin = 0;
            auto end = matrix.size() - 1;
            while(begin < end) {
                swap(matrix[i][begin++], matrix[i][end--]);
            }
        }

    }
    
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9) return false;
        for(int i=0; i<board.size(); i++)
            if (board[i].size()!=9) return false;

        for(int i=0; i<9; i++) {
            unordered_set<char> s1;
            unordered_set<char> s2;
            for (int j=0; j<board[i].size(); j++) {
                auto c1 = board[i][j];
                if(c1=='.') {

                } else if(c1>='1' && c1<='9' && s1.find(c1)==s1.end()) {
                    s1.insert(c1);
                } else {
                    return false;
                }

                auto c2 = board[j][i];
                if(c2=='.') {

                } else if(c2>='1' && c2<='9' && s2.find(c2)==s2.end()) {
                    s2.insert(c2);
                } else {
                    return false;                    
                }

                if(i%3==0 && j%3==0) {
                    unordered_set<char> s3;
                    for(int k=0; k<3; k++) {
                        for(int l=0; l<3; l++) {
                            auto c3 = board[3*(i/3)+k][3*(j/3)+l];
                            if(c3=='.') {
                                
                            } else if(c3>='1' && c3<='9' && s3.find(c3)==s3.end()) {
                                s3.insert(c3);
                            } else {
                                return false;
                            }
                        }
                    }
                        
                }                    
            }
        }    

        return true;
    }
};

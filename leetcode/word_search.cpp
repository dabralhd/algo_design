// https://leetcode.com/problems/word-search/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <iostream>
#include <exception>

using namespace std;

struct node_t {
    int x;
    int y;
    char ch;
    //bool visited;
    node_t(char _ch, int _x, int _y) : ch {_ch }, x {_x }, y { _y }  {}
};

struct node_hasher {
    size_t operator()(const node_t& u) const {
        size_t code {};
        code = hash<char>()(u.ch);
        code = code<<1 ^ hash<int>()(u.x);
        code = code<<1 ^ hash<int>()(u.y);        
        return code;
    }

};

using graph_t = unordered_map<node_t, unordered_set<node_t, node_hasher>, node_hasher>;
using visited_t = unordered_map<node_t, bool, node_hasher>;

bool operator==(const node_t& lhs, const node_t& rhs) {
    return lhs.ch==rhs.ch && lhs.x==rhs.x && lhs.y==rhs.y;
}

ostream& operator<<(ostream& os, node_t node) {
    os << "<" << node.ch << ", " << node.x << ", " << node.y << ">";
    return os;
}

class Solution {
public:
    graph_t makeGraph(const vector<vector<char>>& board) {
        graph_t g;
        const int rows = board.size();
        const int cols = board[0].size();

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                unordered_set<node_t, node_hasher> adj;   
                node_t u {board[r][c], r, c};             
                if(r+1<rows)
                    g[u].insert(node_t{board[r+1][c], r+1, c});
                if(r-1>=0)
                    g[u].emplace(node_t{board[r-1][c], r-1, c});
                if(c+1<cols)
                    g[u].emplace(node_t{board[r][c+1], r, c+1});
                if(c-1>=0)
                    g[u].emplace(node_t{board[r][c-1], r, c-1});
            }
        }
        return g;
    }

    bool dfs_visit(graph_t g, vector<vector<bool>>& visited, node_t u, string str, int pos) {      
        if(!visited[u.x][u.y] && pos < str.size()) {           

             auto it = g.find(u);
             if(it != g.end()) {
                if(pos==str.size()-1 && u.ch==str[pos]) {
                    visited[u.x][u.y] = true;
                    return true;
                } else if(u.ch==str[pos]) {  
                    visited[u.x][u.y] = true;              
                    for(const auto& v : it->second) {                        
                        if(dfs_visit(g, visited, v, str, pos+1)) {                            
                            return true;
                        }
                    } 
                } else {
                    return false;
                }
            }
        }
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        auto g = makeGraph(board);     
        for(int i=0; i<board.size(); i++) {   
            for(int j=0; j<board[i].size(); j++) {
                if( board[i][j]==word[0] ) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));   
                    if(dfs_visit(g, visited, {board[i][j], i, j}, word, 0))
                        return true;
                }
            }
        }
        return false;        
    }
};

ostream& operator<<(ostream& os, const vector<vector<char>>& vc) {
    auto rows = vc.size();
    if(rows) {
        auto cols = vc[0].size();
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                os << vc[r][c] << " ";
            }
            os << endl;
        }
    }
    return os;
}

int main() {
    vector<vector<char>> board(3);

    board[0] = {'a', 'b', 'c', 'e'};
    board[1] = {'s', 'f', 'c', 's'};
    board[2] = {'a', 'd', 'e', 'e'};   

    cout << board;
    string str;
    str = "see";
    //cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;

    str = "abfc";
    //cout << "checking if " << str << "  exists: "<< Solution().exist(board, str) << endl;

    str = "abfe";
    //cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;  

    str = "abccfda";
    //cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;  

    str = "abfcss";
    //cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;  

    str = "abfcse";
    //cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl; 

    str = "abfcsec";
    cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;        

    str = "abfcsecb";
    cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;   

    str = "abfdees";
    cout << "checking if " << str << " exists: "<< Solution().exist(board, str) << endl;                     
}

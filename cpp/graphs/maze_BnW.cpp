// black and white maze

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unordered_set>

using namespace std;

enum class Colour {Black, White};

class Position {
    public:
        int x;
        int y;

        Position() : Position(0, 0)
        {}

        Position(int _x, int _y) : x{ _x }, y{ _y }
        {}

        const Position& left() { return Position(x-1, y); }
        const Position& right() { return Position(x+1, y); }
        const Position& up() { return Position(x, y-1); }        
        const Position& down() { return Position(x, y+1); }

        const Position& try_move(int i) {
            if(i==0) return p.left();
            if(i==1) return p.right();
            if(i==2) return p.up();
            return p.down();
        }

        friend bool operator==(const Position& lhs, const Position& rhs) {
            if((lhs.x==rhs.x) && (lhs.y==rhs.y)) return true;
            return false;
        }
};

void init_maze(vector<vector<int>>& maze) {
    for(int idx=0; idx<maze.size(); ++idx) {
        maze[idx] = vector<int>(maze.size(), 0);
    }

    srand(time(0));

    for(int i=0; i<maze.size(); ++i) {
        for(int j=0; j<maze[i].size(); ++j) 
            maze[i][j] = rand() % 2;
    }
}

void show_maze(vector<vector<int>>& maze) {
    cout << "displaying maze contents: " << endl;
    for(int i=0; i<maze.size(); ++i) {
        for(int j=0; j<maze[i].size(); ++j) 
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

bool isValidMove(const Position& p,
                const vector<vector<int>> maze,
                const unordered_set<Position>& visited
                ) 
    {
        if(visited.find(p)==visited.end() && maze[p.y][p.x]==Colour::White)
            return true;
        return false;
    }

bool dfs(const vector<vector<int>>& graph, 
        const Position& start, 
        const Position& end,
        unordered_set<Position>& visited,
        vector<Position>& path) {
            
            if(start==end) {
                return true;
            }

            path.push_back(start);

            Position next;
            for(int i=0; i<4; ++i) {
                next = start.try_move(i);
                if(isValidMove(next, graph, visited)) {
                    return dfs(graph, next, end, visited, path);
                }
            }

            path.pop_back(start);                         
            
            return false;
        }

int main() {
    int maze_size = 0;
    cout << "enter maze size: " << endl;
    cin >> maze_size;

    vector<vector<int>> maze(maze_size);

    init_maze(maze);
    show_maze(maze);

    return 0;
}
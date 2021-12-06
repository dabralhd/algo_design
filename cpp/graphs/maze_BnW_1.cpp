// black and white maze

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unordered_set>
#include <exception>
#include <cstdlib>

using namespace std;

class Maze {
    private:
        class Coordinates {
            public: 
                int x;
                int y;
                Coordinates(int _x, int _y) : x { _x }, y{ _y }
                {}

                Coordinates() : Coordinates(0, 0)
                {}

                void show() const {
                    cout << x << ": " << y << endl;
                }

                Coordinates& operator +=(const Coordinates& rhs) {
                    x += rhs.x;
                    y += rhs.y;
                    return *this;
                }

                friend Coordinates operator +(const Coordinates& lhs, const Coordinates& rhs) {
                    return Coordinates(lhs.x+rhs.x, lhs.y+rhs.y);
                }

                friend bool operator ==(const Coordinates& lhs, const Coordinates& rhs) {
                    return ((rhs.x==lhs.x)&&(rhs.y==lhs.y));
                }

                Coordinates& operator =(const Coordinates& rhs) {
                    x = rhs.x;
                    y = rhs.y;
                    return *this;
                }
            };
   

        enum class Colour { black, white };
        
        Coordinates maze_dim;
        Coordinates begin, end, cur;
        vector<vector<Colour>> clr;

    public:
        Maze(const int  _dimx, 
            const int  _dimy, 
            const int _bx, 
            const int _by,
            const int _ex, 
            const int _ey,
            const int _cx, 
            const int _cy
            ) : maze_dim(_dimx, _dimy), begin(_bx, _by), end(_ex, _ey), cur(_cx, _cy)
        { 
            // do exception handling            
        }

        // initialize the maze randomly
        void rand_init() {
            srand(time(0));
            clr = vector<vector<Colour>>(maze_dim.y);

            for(int y=0; y<maze_dim.y; ++y) {
                clr[y] = vector<Colour>(maze_dim.x);
                for(int x=0; x<maze_dim.x; ++x) {
                    clr[y][x] = static_cast<Colour> (abs(rand()) % 2);
                }
            }           
            return;
        }

        Coordinates move(const Coordinates& delta) {
            Coordinates pos(cur);
            pos.x += delta.x;
            pos.y += delta.y;
            return pos;
        }

        Coordinates move_left() { return move(Coordinates(-1, 0)); }
        Coordinates move_right() { return move(Coordinates(1, 0)); }
        Coordinates move_up() { return move(Coordinates(0, -1)); }
        Coordinates move_down() { return move(Coordinates(0, 1)); }  

        Coordinates next_move(int i) {
            switch(i % 4) {
                case 0:
                    return move_left();
                    break;
                case 1:
                    return move_right();
                    break;
                case 2:
                    return move_up();
                    break;
                case 3:
                    return move_down();
                    break;
            }

            return move_left();            
        }

        // initialize the maze randomly
        void dfs() {
            vector<vector<bool>> visited(maze_dim.y);
            vector<Coordinates> pos;

            for(int y=0; y<maze_dim.y; ++y) {
                visited[y] = vector<bool>(maze_dim.x);
                for(int x=0; x<maze_dim.x; ++x) {
                    visited[y][x] = false;
                }
            }    
            dfs_visit(visited, pos);

            // show path now
            for(const auto& x : pos) 
                x.show();    

            return;
        }

        bool dfs_visit(vector<vector<bool>>& visited, vector<Coordinates>& pos) {
            if (cur==end)
                return true;

            if(!visited[cur.y][cur.x]) {
                visited[cur.y][cur.x] = true;
                pos.push_back(cur);

                for(int i=0; i<4; ++i) {
                    Coordinates new_pos = next_move(i);
                    if(clr[new_pos.y][new_pos.x]==Colour::white && visited[new_pos.y][new_pos.x]==false) {
                        // visit the path using this node                        
                        begin = new_pos;
                        return dfs_visit(visited, pos);
                    }
                }
                begin = pos.front();
                pos.pop_back();
            }
            return false;    

        }

};

int main() {
    Maze mz(4, 4, 0, 0, 3, 1, 0, 0);
    mz.dfs();   
    return 0;
}
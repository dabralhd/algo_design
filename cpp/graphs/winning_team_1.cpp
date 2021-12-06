#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    private:
        int N;
        list<int>* adj;
    public:
        Graph(int node_count) : N(node_count) {
            adj = new list<int>[N];
        }

        void addEdge(int winner, int loser) {
            adj[winner].push_back(loser);            
        }

        bool canBeat(int team_a, int team_b, vector<int>& path) {
            vector<bool> visited(N, false);

            return dfs(team_a, team_b, visited, path);
        }

        bool dfs(const int team_a, 
                    const int team_b, 
                    vector<bool>& visited,
                    vector<int>& path) {

            visited[team_a] = true;
            path.push_back(team_a);

            if(team_a == team_b) {
                cout << team_a << " can beat " << team_b << endl;
                return true;
            }

            for(const auto& v : adj[team_a]) {
                if(visited[v]==false) {
                    bool result = dfs(v, team_b, visited, path);  
                    if(result) {
                        
                    } else {
                        path.pop_back();
                    }
                    return result;
                }
            }

            return false;
        }
};

int main() {
    Graph g(6);
    vector<int> path;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);    

    cout << g.canBeat(0, 5, path) << endl;

    for(const auto& v : path)
        cout << v << "-->";
}
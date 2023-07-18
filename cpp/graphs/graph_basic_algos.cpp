#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Graph {
    int num_vertices;
    vector<vector<int>> adj;
    void dfs_helper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for(auto v : adj[u]) {
            if(!visited[v]) { 
                dfs_helper(v, visited);
            }
        }

    }
    public: 
        Graph(int v_count, const vector<pair<int, int>>& edges) : num_vertices{v_count}, adj {vector<vector<int>>(v_count)} {            
            for(const auto p : edges) {
                adj[p.first].push_back(p.second);
                adj[p.second].push_back(p.first);
            }
        }

        void dfs(int start) {
            vector<bool> visited = vector<bool>(num_vertices, false);
            dfs_helper(start, visited);
        }


};

void test_dfs_traversal_helper() {
    Graph g {10, {{0,1}, {1,2}/*, {3,4}, {4,5}, {5,1}*/}};
    cout << endl << "dfs: ";
    g.dfs(0); 
}

int main() {
    test_dfs_traversal_helper();
}
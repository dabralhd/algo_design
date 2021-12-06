#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

class MatchResult {
    public:
        string winner, loser;
        MatchResult(const string& first, const string& second) : winner { first }, loser { second }
        {}    
};

const unordered_map<string, unordered_set<string>> build_graph(const vector<MatchResult>& edges) {
    unordered_map<string, unordered_set<string>> graph;

    for(const auto& edge : edges) {
        graph[edge.winner].emplace(edge.loser);
    }
    return graph;
}



#if 1
bool canBeat(const unordered_map<string, unordered_set<string>>& graph, 
            const string& src, 
            const string& dest, 
            unordered_set<string>& visited) {

    if(src == dest) 
        return true;

    visited.emplace(src);

    try {
        const auto dest_set = graph.at(src);
        for(const auto& node : dest_set) {
            if(visited.find(node)==visited.end()) 
                return canBeat(graph, node, dest, visited);
        }
    } catch (exception e) {
        //cout << e.what() << endl;
        return false;
    }

    return false;
}
#endif

void bfs(const unordered_map<string, unordered_set<string>>& adj, const string& src) {
    queue<string> q;
    unordered_map<string, int> d;
    unordered_map<string, string> p;

    for(const auto& edge : adj) {
        d[edge.first] = numeric_limits<int>::max();
        for(const auto& v : edge.second)
            d[v] = numeric_limits<int>::max();
    }
    
    // visit source
    cout << src << "->";
    d[src] = 0;
    p[src] = "-";
    q.push(src);

    while(!q.empty()) {
        const string u = q.front();
        q.pop();
        try {
            for(const auto& v:adj.at(u)) {
                if(d[v]==numeric_limits<int>::max()) {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
        } catch (exception e) {

        }
    }

    cout << "showing distances, src: " << src << endl;
    for(const auto& v : d) {
        cout << v.first << ": " << v.second << endl;
    }

    cout << "showing precedence, src: " << src << endl;
    for(const auto& v : p) {
        cout << v.first << ": " << v.second << endl;
    }
}

void show_graph(const unordered_map<string, unordered_set<string>>& graph) {
    cout << "showing graph nodes: " << endl;
    for(const auto& winner : graph) {
        cout << winner.first << ": ";
        for(const auto& loser : winner.second) {
            cout << loser << ", ";
        }
        cout << endl;
    }

}

void make_graph1() {
    vector<MatchResult> results;
    results.push_back(MatchResult("a", "b"));
    results.push_back(MatchResult("b", "c"));
    results.push_back(MatchResult("c", "d"));
    results.push_back(MatchResult("d", "a"));
    results.push_back(MatchResult("d", "e"));
    results.push_back(MatchResult("d", "f"));
    results.push_back(MatchResult("f", "h"));

    const auto& graph = build_graph(results);
    show_graph(graph);

    unordered_set<string> visited;

    cout << "can d beat a: " << canBeat(graph, "d", "a", visited) << endl;

    string bfs_start_node = "a";
    cout << "now running bfs, starting from: " << bfs_start_node << endl;
    bfs(graph, bfs_start_node);
}

int main() {
    make_graph1();
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Match {
    public:
        string winner, loser;
        Match(string a, string b) : winner(a), loser(b)
        { }
        Match() = delete;
};

unordered_map<string, unordered_set<string>> build_graph(vector<Match> matches) {
    unordered_map<string, unordered_set<string>> graph;

    for(const auto& match : matches) {
        graph[match.winner].insert(match.loser);
    }

    return graph;
}

bool dfs_visit(const unordered_map<string, unordered_set<string>>& graph, 
            const string& team_a,
            const string& team_b,
            unordered_map<string, bool>& visited, 
            vector<string>& path) {
                visited[team_a] = true;

                if(visited.find(team_a)!=visited.end()) {
                    if(graph.find(team_a)==graph.end()) {                
                        return false;   
                    }  
                    return false;           
                }

                path.push_back(team_a);

                if(team_a==team_b)
                    return true;
                   
                for(const auto& v : graph.at(team_a)) {
                    if(visited.find(v)==visited.end()) {
                        return dfs_visit(graph, v, team_b, visited, path);                            
                    }
                }

                path.pop_back();
                return false;
}

vector<string> get_sequence(const vector<Match>& matches, 
                            const string& team_a, 
                            const string& team_b) {
                                
        unordered_map<string, unordered_set<string>> graph = build_graph(matches);
        unordered_map<string, bool> visited(false);
        vector<string> path;
        dfs_visit(graph, team_a, team_b, visited, path);

        cout << "path is: " << endl;
        for(const auto& team : path)
            cout << team << ", ";
        cout << endl;
        return path;
}

int main() {
    vector<Match> v;
    v.push_back(Match("a", "b"));
    v.push_back(Match("a", "c"));
    v.push_back(Match("b", "d"));
    v.push_back(Match("a", "e"));

    get_sequence(v, "a", "d");
    return 0;
}
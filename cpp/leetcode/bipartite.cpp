using namespace std;

class Solution {
public:
    vector<int> get_union(vector<int> x, const vector<int> y) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        vector<int>::iterator itr;
        vector<int> z(x.size()+y.size());
        
        itr = set_union(x.begin(), x.end(), y.begin(), y.end(), z.begin());
        z.resize(itr - z.begin());
        
        return z;            
    }
    
    vector<int> get_intersection(vector<int> x, const vector<int> y) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        vector<int>::iterator itr;
        vector<int> z(x.size()+y.size());
        
        itr = set_intersection(x.begin(), x.end(), y.begin(), y.end(), z.begin());
        z.resize(itr - z.begin());
        
        return z;            
    }    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        const int size = graph.size();
        vector<int> A, B, all;
        
        cout << "pushing into all:" << endl;        
        for(int i=0; i<size; ++i) {    
            cout << i << " ";          
            all.push_back(i);        
        }
        cout << endl;
        
        // find x for u=0
        cout << "determining set A:" << endl;
        int u = 0;
        A = graph[u];
        
        for(int i=1; i<graph.size(); ++i) {
            vector<int> tmp;
            tmp=get_intersection(A, graph[i]);
            if(tmp.empty()) 
                continue;
            else {
                vector<int> A_dash = get_union(A, graph[i]);
                A.erase(A.begin(), A.end());
                A = A_dash;
            }
        }
        
        vector<int> x;
        vector<int>::iterator itr;        
        itr = set_difference(all.begin(), all.end(), A.begin(), A.end(), x.begin());
        x.resize(itr - x.begin());
        
        if(x.empty())
            return false;
        B = graph[x[0]];
       
        for(int i=1; i<graph.size(); ++i) {
            vector<int> tmp;
            tmp=get_intersection(B, graph[i]);
            if(tmp.empty()) 
                continue;
            else {
                vector<int> B_dash = get_union(B, graph[i]);
                B.erase(B.begin(), B.end());
                B = B_dash;
            }
        }
        
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> tmp1, tmp2;     
        tmp1=get_intersection(A, B);
        tmp2=get_union(A, B);
        if(tmp1.empty() && tmp2.size()==size)
            return true;
        
        return false;
    } 

};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    queue <pair<int,int>> q;
    int fg=0;
    
    void bfs(vector<int> adj[] , int so , vector <int> &vis){
        

        for(auto j : adj[so]){
            
            pair <int,int> val(j,so);
            q.push(val);
            
        }
        
        vis[so]=1;
        // int pre=so;
        
        while(!q.empty()){
            
            pair <int,int> v1;
            
            v1 = q.front();
            q.pop();
            vis[v1.first]=1;
            
            for( auto j : adj[v1.first]){
                
                if(v1.second!=j and vis[j]==1){
                    fg=1;
                    return;
                }
                
                pair<int,int> p(j,v1.first);
                
                if(v1.second!=j)
                    q.push(p);
    
            }
            
            // pre=v1.first;
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        fg=0;
        
        for(int i=0 ; i<V ; i++){
            
            vector <int> vis(V,0);
            
            bfs( adj , i , vis );
            
            if(fg) break;
            
        }
        
        return fg;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
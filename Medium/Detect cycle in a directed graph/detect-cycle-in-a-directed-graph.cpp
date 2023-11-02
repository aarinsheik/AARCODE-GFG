//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        
    bool dfs( vector<int> adj[] , int so , vector <int> &vis , vector <int> &pvis ){
        
        vis[so]=1;
        pvis[so]=1;
        
        for(auto j : adj[so]){
            
            if(vis[j] and pvis[j]) return true;
            
            if(!vis[j]){
                if( dfs(adj,j,vis,pvis) == true ) return true;
            }
        }
        
        pvis[so]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector <int> vis(V,0) , pvis(V,0) ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(dfs( adj , i ,vis , pvis) == true) return true ;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    
    bool dfs( vector<int> adj[] , int so , vector <int> &vis , vector <int> &pvis , stack <int> &st ){
        
        vis[so]=1;
        pvis[so]=1;
        
        for(auto j : adj[so]){
            
            if(vis[j] and pvis[j] ) return true;
            
            if(!vis[j])
                if( dfs(adj , j , vis , pvis , st ) ) return true;
            
        }
        pvis[so]=0;
        st.push(so);
        return false;
    }
    
    vector<int> findOrder(int V, int m, vector<vector<int>> preq) 
    {
        //code here
        vector<int> adj[V];
	    
	    for(int i=0 ; i<preq.size() ; i++){
	        adj[ preq[i][1] ].push_back( preq[i][0] );
	    }
	    
	    vector <int> vis(V,0) , pvis(V,0);
	    stack <int> st;
	    
	    for(int i=0 ; i<V ; i++){
	        if(!vis[i]){
	            if(dfs( adj , i , vis , pvis , st)) return {};
	        }
	    }
	    
	    vector <int> res;
	    while(!st.empty()){
	        res.push_back( st.top() );
	        st.pop();
	    }
	    
	    return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
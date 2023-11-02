//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	int val=1;
    
    void dfs(vector<int> adj[] , int so , int avo , vector<int> &vis){
        
        vis[so]=1;
        
        for(auto j : adj[so]){
            if(j==avo){
                continue;
            }
            if(!vis[j]){
                dfs(adj,j,avo,vis);
            }
        }
        
    }
    
    int check_B( vector<int> &vis1 , vector<int> &vis2 , int V){
        for(int i=0 ; i<V ; i++){
            if(vis1[i]==1 and vis2[i]==1){
                return 0;
            }
        }
        
        return 1;
    }

	int isBridge(int V, vector<int> adj[], int c, int d){
	    // Code here
	    vector <int> vis1(V,0) , vis2(V,0);
	    
	    
	    
	    dfs(adj,c,d,vis1);
	    dfs(adj,d,c,vis2);
	    
	    return check_B(vis1,vis2 , V);
	}
    //Function to find if the given edge is a bridge in graph.
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends
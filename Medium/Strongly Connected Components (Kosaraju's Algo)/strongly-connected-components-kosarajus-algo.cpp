//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs( vector<vector<int>>& adj , vector <int> &vis , int so , stack <int> &st ){
	    
	    vis[so]=1;
	    
	    for(auto i : adj[so] ){
	        if(!vis[i]){ 
	            dfs(adj,vis,i,st);
	        }
	    }
	    st.push(so);
	}
	
	void dfs2( vector<int> adj[] , vector <int> &vis , int so , stack <int> &st ){
	    
	    vis[so]=1;
	    
	    for(auto i : adj[so] ){
	        if(!vis[i]){ 
	            dfs2(adj,vis,i,st);
	        }
	    }
	}
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack <int> st;
        vector <int> vis(V,0);
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs(adj , vis , i , st);
            }
        }
        
        vector<int> rev[V] ;
        
        for(int i=0 ;i<V ; i++){
            for(auto j : adj[i]){
                rev[j].push_back(i);
            }
        }
        
        vector <int> vis2(V,0);
        int co=0;
        
        while(!st.empty()){
            
            int k=st.top();
            
            if(!vis2[k]){
                dfs2(rev , vis2 , k , st);
                co++;
            }
            else
                st.pop();
                    
        }
        
        return co;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
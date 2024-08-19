//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	
	void DFS( vector<int> adj[] , int i , int x , vector<int> &vis , bool &fd , int &lev ){
	   
	   if(vis[i] or fd){
	       	return;
	    }
	    
	    if(i==x){
	        fd=true;
	        return;
	    }
	    
	    vis[i]=1;
	    lev=lev+1;
	    
        for(int p : adj[i]){
            DFS( adj , p , x , vis , fd , lev );
        }
	    
	    if(fd) return ;
	    lev=lev-1;
	}
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<int> vis( V , 0 );
	    
	    bool fd = false;
	    
	    int lev=0;
	    
	    DFS( adj , 0 , X , vis , fd , lev );
	    
	    if(!fd) return -1;
	    
	    return lev;
	    
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int val=1;
    
    void dfs( vector<int> adj[] , int so , int par , vector<int> &vis , vector<int> &low ,
                vector<int> &tim , vector<vector<int>> &res) {
                    
        
        tim[so]=val;
        low[so]=val;
        val++;
    
        vis[so]=1;
        
        
        for(auto j : adj[so] ){
            
            if(j==par) continue;
            
            if( !vis[j] ){
                
                dfs(adj , j , so , vis , low , tim , res);
                low[so] = min(low[so],low[j]);
                
                if(low[j]>tim[so]){
                    
                    vector<int> t({j,so});
                    sort(t.begin() , t.end() );
                    res.push_back(t);
                
                }
            }
            else{
                low[so] = min( low[so],low[j] );
            }
        }
        
    }

	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector <int> low(V) , tim(V) , vis(V,0) ;
	    vector<vector<int>> res ;
	    val=1;
	
        dfs(adj , 0 , -1 , vis , low , tim , res);
	    
	    sort(res.begin() , res.end());     
	    return res;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
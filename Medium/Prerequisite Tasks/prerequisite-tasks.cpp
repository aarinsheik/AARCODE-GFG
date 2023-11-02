//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool dfs( vector<int> adj[] , int so , vector <int> &vis , vector <int> &pvis ){
        
        vis[so]=1;
        pvis[so]=1;
        
        for(auto j : adj[so]){
            
            if(vis[j] and pvis[j] ) return true;
            
            if(!vis[j])
                if( dfs(adj , j , vis , pvis ) ) return true;
            
        }
        pvis[so]=0;
        return false;
    }
    
	bool isPossible(int V,int P, vector<pair<int, int> >& preq) {
	    // Code here
	    vector<int> adj[V];
	    
	    for(int i=0 ; i<preq.size() ; i++){
	        adj[ preq[i].first ].push_back( preq[i].second );
	    }
	    
	    vector <int> vis(V,0) , pvis(V,0);
	    
	    for(int i=0 ; i<V ; i++){
	        if(!vis[i]){
	            if(dfs( adj , i , vis , pvis )) return false;
	        }
	    }
	    
	    return true;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <chrono>
using namespace std::chrono;

class Solution {
  public:
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> path(N, INT_MAX );
        map<int,int> vis;
        queue<int> q;
        
        vector<vector<int>> ed(N);
        
        for(int i=0; i<M ; i++){
            ed[edges[i][0]].push_back(edges[i][1]);
            ed[edges[i][1]].push_back(edges[i][0]);
        }
        

        q.push(src);
        path[src]=0;
        vis[src]++;
        
        while(!q.empty()){
            
            int pr = q.front();
            q.pop();
            vis[pr]++;
            
            for(int i : ed[pr] ){
                if(!vis[i]){
                    q.push(i);
                    path[i] = min(path[i] , path[pr]+1) ;
                }
            }
        }
        
        for(int i=0 ; i<N ; i++){
            if(path[i]==INT_MAX)
                path[i]=-1;
        }
        
        return path;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
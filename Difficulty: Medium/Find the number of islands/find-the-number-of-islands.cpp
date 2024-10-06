//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& gd , vector<vector<int>> &vis , int r , int c ){
        
        vis[r][c]=1;
        int d1[]={1,-1,0,0,1,-1,-1,1};
        int d2[]={0,0,1,-1,1,-1,1,-1};
        
        for(int i=0 ; i<8 ; i++){
            
            if(r+d1[i]>=0 and r+d1[i]<gd.size() and c+d2[i]>=0 and c+d2[i]<gd[0].size() ){
                if( vis[ r+d1[i] ][ c+d2[i] ]==0 and  gd[ r+d1[i] ][ c+d2[i] ]=='1' ){
                    dfs(gd,vis,r+d1[i],c+d2[i]);
                }            
            }
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<int>> vis( grid.size() , vector<int> (grid[0].size(),0)); 
        int co=0;
        
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                
                if(grid[i][j]=='1' and vis[i][j]==0){
                    dfs(grid , vis , i , j );
                    co++;
                }
                
            }
        }
        
        return co;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    void allPath(  pair<int,int> ini ,vector<vector<int>> &mat, stack<char> &path, map< pair<int,int> , int> &vis,  vector<string> &res ){
        
        int dr[4] = { -1 , 0 , 1 , 0};
        int dc[4] = { 0 , 1 , 0 , -1};
        char dst[4] = {'U' , 'R' , 'D' , 'L' };
        
        int n = mat.size();
        
        if( !vis[ini] ){
            vis[ini]=1;
        }
        
        if( ini.first==n-1 and ini.second==n-1 ){
            
            string p ;
            p.clear();
            stack<char> cpy = path;
            
            while( !cpy.empty() ){
                p = cpy.top() + p ;
                cpy.pop();
            }
            
            res.push_back(p);
        }
        
        for(int i=0 ; i<4 ; i++){
            
            int r = ini.first+dr[i];
            int c = ini.second+dc[i];
            //vis mark
            pair<int,int> ndir(r,c);

            if(r>=0 and r<=n-1 and c>=0 and c<=n-1 ){
                if( mat[r][c]==1 and !vis[ndir] ){
                    
                    path.push(dst[i]);
                    allPath( ndir, mat , path , vis , res );
                    path.pop();
                }
            }
            
        }
        
        if( vis[ini] ){
            vis[ini]=0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> res;
        map< pair<int,int> , int> vis; 
        stack<char> path;
        
        pair<int,int> ini(0,0);
        
        if(mat[0][0]==0){
            res.push_back("-1");
            return res;
        }
        
        allPath( ini , mat , path , vis, res );
        
        if( res.empty() ){
            res.push_back("-1");
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
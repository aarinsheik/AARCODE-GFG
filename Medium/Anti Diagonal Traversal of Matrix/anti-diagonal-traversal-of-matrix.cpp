//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code here
        int m = mat.size() , n = mat[0].size() ;
        int r=0 , b=0 ;
        vector<int> res ;
        
        for(int i=0 ; i<n ; i++){
            
            b=0;
            r=i;
            while(r>=0 and b>=0 and b<m){
                res.push_back(mat[b][r]);
                r--;
                b++;
            }
              
        }
        
        for(int i=1 ; i<m ; i++ ){
            
            b=n-1;
            r=i;
            while(b>=0 and r<m and r>=0){
                res.push_back(mat[r][b]);
                r++;
                b--;
            }
            
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
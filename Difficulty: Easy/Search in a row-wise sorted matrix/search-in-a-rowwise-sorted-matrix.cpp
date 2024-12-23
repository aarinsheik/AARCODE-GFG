//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size() , m = mat[0].size() ;
        int i=0 ;
        while(i<n){
            
            if(!(x>=mat[i][0] and x<=mat[i][m-1])) i++;
            else{
                for(int j=0 ; j<m ; j++){
                    
                    vector<int> v = mat[i];
                    auto it = find(v.begin(), v.end(), x);
                
                    if( it!=v.end() ){
                        return true;
                    }
                    
                }
                i++;
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
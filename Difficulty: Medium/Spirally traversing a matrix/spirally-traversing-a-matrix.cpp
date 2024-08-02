//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        map< pair<int,int> , int> vis;
        vector<int> res;
                
        int dr[]={ 0 , 1 , 0 , -1 };
        int dc[]={ 1 , 0 , -1 , 0 };
        int d=0 , i=0 , j=0 ;
        
        int sz = mat.size()*mat[0].size();
        
        while(sz){
            
            res.push_back(mat[i][j]);
            sz--;
            vis[ {i,j} ]=1;
        
            while( sz!=0 and ( i+dr[d]>=mat.size() or j+dc[d]>=mat[0].size() or vis[{ i+dr[d] , j+dc[d] }] ) ){
                d=(d+1)%4;
            }
            
            i = i+dr[d] ;
            j = j+dc[d] ;
            
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
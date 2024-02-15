//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int FindCoverage(vector<vector<int>>&mat){
        // Code here
        int n = mat.size() , m=mat[0].size() , co=0 ;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
            
                if(mat[i][j]==0 ){
                    
                    if(i-1>=0 and mat[i-1][j]==1 ){
                        co++;
                    }
                    if(i+1<n and mat[i+1][j]==1 ){
                        co++;
                    }
                    if(j-1>=0 and mat[i][j-1]==1 ){
                        co++;
                    }
                    if(j+1<m and mat[i][j+1]==1 ){
                        co++;
                    }
                }
            }
        }
        
        return co;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
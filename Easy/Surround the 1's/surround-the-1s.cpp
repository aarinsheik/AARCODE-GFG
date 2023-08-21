//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& mat) {
        // Code here
        int co=0 , coz=0 , k1 = mat.size() , k2 = mat[0].size(); ;
        
        for(int i=0 ; i<k1 ; i++){
            for(int j=0 ; j<k2 ; j++){
                
                coz=0;
                if(mat[i][j]==1){
                    
                    int a = i , b = j;
                    
                    if((a-1)>=0 and (b-1)>=0 and mat[a-1][b-1]==0){
                        coz++;
                    }
                    if((a)>=0 and (b-1)>=0 and mat[a][b-1]==0){
                        coz++;
                    }
                    if((a+1)<k1 and (b-1)>=0 and mat[a+1][b-1]==0){
                        coz++;
                    }
                    
                    if((a-1)>=0 and (b)>=0 and mat[a-1][b]==0){
                        coz++;
                    }
                    if((a+1)<k1 and (b)>=0 and mat[a+1][b]==0){
                        coz++;
                    }
                    
                    if((a-1)>=0 and (b+1)<k2 and mat[a-1][b+1]==0){
                        coz++;
                    }
                    if((a)>=0 and (b+1)<k2 and mat[a][b+1]==0){
                        coz++;
                    }
                    if((a+1)<k1 and (b+1)<k2 and mat[a+1][b+1]==0){
                        coz++;
                    }
                    
                }
                
                if(coz!=0 and coz%2==0){
                    co++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
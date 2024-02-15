//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> FindExitPoint(vector<vector<int>>&mat){
		// Code here
		int i=0 , j=0 , r=0 ;
		int n=mat.size() , m=mat[0].size() ;
		
		while( i>=0 and i<n and j>=0 and j<m ){
		    if(mat[i][j]==1 ){
                r++;
		        mat[i][j]=0;
            }
            
            switch (r%4) {
                case 0 :
                    j++;
                    if(j>=m) return {i,j-1} ; 
                    break;
                    
                case 1 :
                    i++;
                    if(i>=n) return {i-1,j} ; 
                    break;
                
                case 2 :
                    j--;
                    if(j<0) return {i,j+1} ; 
                    break;
                
                case 3 :
                    i--;
                    if(i<0) return {i+1,j} ; 
                    break;
                    
                default :
                    cout<<"Err";
            }
		    
		}
		
		return {0,0};
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
		vector<int> ans = obj.FindExitPoint(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends